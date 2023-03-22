#include<iostream>
using namespace std;

class node{
    public:
        int item;
        int height;
        node *left;
        node *right;

        node(int item):item(item), height(1), left(NULL), right(NULL){}

};

class AVL{

    private:
        node *root;
    
    protected:
        node* leftRotate(node*);
        node* rightRotate(node*);
        node* insertion(node*, int);
        void preOrder(node*);
        void inOrder(node*);
        void postOrder(node*);
        node* deletion(node*, int);
    
    public:
        AVL();
        bool isEmpty();
        int getHeight(node*);
        int getBalanceFactor(node*);
        void insert(int);
        void display();
        void del(int);

};

AVL::AVL(){
    root = NULL;
}

bool AVL::isEmpty(){
    return root==NULL;
}

int AVL::getHeight(node *n){
    if(n==NULL)
        return 0;
    return n->height;
}

int AVL::getBalanceFactor(node *n){
    if(n==NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

node* AVL::leftRotate(node *n){
    node *A = n->right;
    node *A_LT = A->left;

    A->left = n;
    n->right = A_LT;

    n->height = max(getHeight(n->left), getHeight(n->right))+1;
    A->height = max(getHeight(A->left), getHeight(A->right))+1;

    return A;
}

node* AVL::rightRotate(node *n){
    node *A = n->left;
    node *A_RT = A->right;

    A->right = n;
    n->left = A_RT;

    n->height = max(getHeight(n->left), getHeight(n->right))+1;
    A->height = max(getHeight(A->left), getHeight(A->right))+1;

    return A;
}

node* AVL::insertion(node *n, int item){
    if(n==NULL){
        node *newNode = new node(item);
        return newNode;
    }
    else if(item<n->item)
        n->left = insertion(n->left, item);
    else if(item>n->item)
        n->right = insertion(n->right, item);
    else
        return n;
    
    n->height = max(getHeight(n->left), getHeight(n->right))+1;

    int balance = getBalanceFactor(n);

    // left-left case
    if(balance>1 && item<n->left->item)
        return rightRotate(n);

    // right-right case
    if(balance<-1 && item>n->right->item)
        return leftRotate(n);
    
    // left-right case
    if(balance>1 && item>n->left->item){   
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    
    // right-left case
    if(balance<-1 && item<n->right->item){
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }

    return n;
}

void AVL::insert(int item){
    root = insertion(root, item);
}

node* AVL::deletion(node *n, int item){
    if(n==NULL)
        return NULL;
    else if(item<n->item)
        n->left = deletion(n->left, item);
    else if(item>n->item)
        n->right = deletion(n->right, item);
    else{
        if(n->left==NULL && n->right==NULL){    //no-child
            delete n;
            return NULL;
        }
        if(n->left==NULL || n->right==NULL){   //single-child
            node *temp = n->left?n->left:n->right;
            delete n;
            return temp;
        }
        //two-child (Get in-order Successor)
        node *par = n;
        node *curr = n->right;
        while(curr->left){
            par = curr;
            curr = curr->left;
        }
        n->item = curr->item;
        if(par->left==curr)
            par->left = deletion(curr, curr->item);
        else
            par->right = deletion(curr, curr->item);
    }

    // if the tree only had one node i.e., the root node.
    if(n==NULL)
        return NULL;

    n->height = max(getHeight(n->left), getHeight(n->right))+1;

    int balance = getBalanceFactor(n);

    //left-left case:
    if(balance>1 && getBalanceFactor(n->right)>=0)
        return rightRotate(n);
    
    //right-right case:
    if(balance<-1 && getBalanceFactor(n->left)<=0)
        return leftRotate(n);

    //left-right case:
    if(balance>1 && getBalanceFactor(n->left)<0){
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }

    //right-left case:
    if(balance<-1 && getBalanceFactor(n->right)>0){
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }

    return n;
    
}

void AVL::del(int item){
    root = deletion(root, item);
}

void AVL::preOrder(node *n){
    if(n==NULL)
        return;
    
    cout<<n->item<<"("<<getBalanceFactor(n)<<") ";
    preOrder(n->left);
    preOrder(n->right);
}

void AVL::inOrder(node *n){
    if(n==NULL)
        return;
    
    inOrder(n->left);
    cout<<n->item<<"("<<getBalanceFactor(n)<<") ";
    inOrder(n->right);
}

void AVL::postOrder(node *n){
    if(n==NULL)
        return;
    
    postOrder(n->left);
    postOrder(n->right);
    cout<<n->item<<"("<<getBalanceFactor(n)<<") ";
}

void AVL::display(){
    cout<<"Pre-Order Traversal: ";
    preOrder(root);
    cout<<"\n";
    cout<<"In-Order Traversal: ";
    inOrder(root);
    cout<<"\n";
    cout<<"Post-Order Traversal: ";
    postOrder(root);
    cout<<"\n";
}

int main(){
    AVL t;

    t.insert(21);
    t.insert(26);
    t.insert(30);
    t.insert(9);
    t.insert(4);
    t.insert(14);
    t.insert(28);
    t.insert(18);
    t.insert(15);
    t.insert(10);
    t.insert(2);
    t.insert(3);
    t.insert(7);

    t.display();
    cout<<"\n";

    t.del(2);
    t.del(3);
    t.del(10);
    t.del(18);
    t.del(4);
    t.del(9);
    t.del(14);
    t.del(7);
    t.del(15);
    t.display();

    return EXIT_SUCCESS;
}