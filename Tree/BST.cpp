#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

class node{

    public:
        int item;
        node *left;
        node *right;

        node(int item):item(item), left(NULL), right(NULL){}
};

class BST{

    private:
        node *root;
        bool isDeleted;
        void preOrder_trav(node*);
        void inOrder_trav(node*);
        void postOrder_trav(node*);
        void levelOrder_trav(node*);
        node* deleteNode_by_inOrder_Predecessor(node*, int);
        node* deleteNode_by_inorder_Successor(node*, int);
        node* deleteTree(node*);

    public:
        BST();
        ~BST();
        bool isEmpty();
        void insert(int);
        void preOrder();
        void inOrder();
        void postOrder();
        void levelOrder();
        bool del(int);
        node* search(int);
};

BST::BST(){
    root = NULL;
    this->isDeleted = 0;
}

node* BST::deleteTree(node *n){
    if(n==NULL)
        return n;
    n->left = deleteTree(n->left);
    n->right = deleteTree(n->right);
    delete n;
    return NULL;

}

BST::~BST(){
    root = deleteTree(root);
}

bool BST::isEmpty(){
    return root==NULL;
}

void BST::insert(int item){
    node *newNode = new node(item);
    if(isEmpty()){
        root = newNode;
    }
    else{
        node *parent = NULL;
        node *current = root;
        while(current)
            if(item<current->item){
                parent = current;
                current = current->left;
            }
            else if(item>current->item){
                parent = current;
                current = current->right;
            }
            else{
                delete newNode;
                return;
            }
        if(item<parent->item)
            parent->left = newNode;
        else
            parent->right = newNode;
    }
}

void BST::preOrder_trav(node *n){
    if(n==NULL)
        return;
    
    cout<<n->item<<", ";
    preOrder_trav(n->left);
    preOrder_trav(n->right);
    
}

void BST::preOrder(){
    if(isEmpty()){
        cout<<"Empty Tree\n";
        return;
    }
    preOrder_trav(root);
}

void BST::inOrder_trav(node *n){
    if(n==NULL)
        return;
    
    inOrder_trav(n->left);
    cout<<n->item<<", ";
    inOrder_trav(n->right);
}

void BST::inOrder(){
    if(isEmpty()){
        cout<<"Empty Tree\n";
        return;
    }
    inOrder_trav(root);
}

void BST::postOrder_trav(node *n){
    if(n==NULL)
        return;
    
    postOrder_trav(n->left);
    postOrder_trav(n->right);
    cout<<n->item<<", ";
}
void BST::postOrder(){
    if(isEmpty()){
        cout<<"Empty Tree\n";
        return;
    }
    postOrder_trav(root);
}

void BST::levelOrder(){
    if(isEmpty()){
        cout<<"Empty Tree\n";
        return;
    }
    queue <node*> q;
    q.push(root);
    while(!q.empty())
        for(int i=0; i<q.size(); i++){
            node *n = q.front();
            q.pop();
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
            cout<<n->item<<", ";
        }
}

node* BST::deleteNode_by_inOrder_Predecessor(node *n, int item){
    if(n==NULL)
        return NULL;
    else if(item<n->item)
        n->left = deleteNode_by_inOrder_Predecessor(n->left, item);
    else if(item>n->item)
        n->right = deleteNode_by_inOrder_Predecessor(n->right, item);
    else{
        if(n->left==NULL && n->right==NULL){    // No-child
            delete n;
            this->isDeleted = 1;
            return NULL;
        }
        if(n->left==NULL || n->right==NULL){    // Single-child
            node *temp = (n->left)?n->left:n->right;
            delete n;
            this->isDeleted = 1;
            return temp;
        }
        // Two-child
        node *parent = n;
        node *curr = n->left;
        while(curr->right){
            parent = curr;
            curr = curr->right;
        }
        n->item = curr->item;
        if(parent->right==curr)
            parent->right = deleteNode_by_inOrder_Predecessor(curr, curr->item);
        else
            parent->left = deleteNode_by_inOrder_Predecessor(curr, curr->item);
    }
    return n;
}

node* BST::deleteNode_by_inorder_Successor(node *n, int item){
    if(n==NULL)
        return NULL;
    else if(item<n->item)
        n->left = deleteNode_by_inorder_Successor(n->left, item);
    else if(item>n->item)
        n->right = deleteNode_by_inorder_Successor(n->right, item);
    else{
        if(n->left==NULL && n->right==NULL){    // No-child
            delete n;
            this->isDeleted = 1;
            return NULL;
        }
        if(n->left==NULL || n->right==NULL){    // Single-child
            node *temp = (n->left)?n->left:n->right;
            delete n;
            this->isDeleted = 1;
            return temp;
        }
        // Two-child
        node *parent = n;
        node *curr = n->right;
        while(curr->left){
            parent = curr;
            curr = curr->left;
        }
        n->item = curr->item;
        if(parent->left==curr)
            parent->left = deleteNode_by_inorder_Successor(curr, curr->item);
        else
            parent->right = deleteNode_by_inorder_Successor(curr, curr->item);
    }
    return n;
}

bool BST::del(int item){
    srand(time(NULL));  //randomly selecting deletion strategy
    if(rand()%2)
        deleteNode_by_inorder_Successor(root, item);
    else
        deleteNode_by_inOrder_Predecessor(root, item);
    bool temp_isDel = this->isDeleted;
    this->isDeleted = 0;
    return temp_isDel;
}

node* BST::search(int item){
    node *temp = root;
    while(temp && temp->item!=item)
        if(item<temp->item)
            temp = temp->left;
        else
            temp = temp->right;
    
    return temp;
}

int main(){
    BST t;
    t.insert(25);
    t.insert(10);
    t.insert(18);
    t.insert(60);
    t.insert(40);
    t.insert(100);
    t.insert(35);
    t.insert(50);
    t.insert(30);

    t.del(25);
    t.del(100);
    t.del(35);

    t.preOrder();
    cout<<"\n";
    t.inOrder();
    cout<<"\n";
    t.postOrder();
    cout<<"\n";
    t.levelOrder();

    return EXIT_SUCCESS;
}