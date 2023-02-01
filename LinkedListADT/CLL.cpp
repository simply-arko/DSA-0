#include<iostream>
#include<stdio.h>
using namespace std;

class node{
    
    public:
        int item;
        node *next;

        node(int item):item(item), next(NULL){}
};

class CLL{      // Circular Linked-List

    private:
        node *last;

    public:
        CLL();
        ~CLL();
        bool isEmpty();
        void addFirst(int);
        void addLast(int);
        node* linearSearch(int);
        void addAfter(node*, int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
};

CLL::CLL(){
    last = NULL;
}

CLL::~CLL(){
    while(last)
        deleteFirst();
}

bool CLL::isEmpty(){
    return last == NULL;
}

void CLL::addFirst(int item){
    node *newNode = new node(item);
    if(isEmpty())
        last = newNode;
    else
        newNode->next = last->next;
    last->next = newNode;
}

void CLL::addLast(int item){
    addFirst(item);
    last = last->next;
}

node* CLL::linearSearch(int num){
    if(isEmpty()){
        cout<<"Empty List"<<endl;
        return NULL;
    }
    node *temp = last; 
    do{
        if(temp->item == num)
            return temp;
        temp = temp->next;
    }while(temp!=last);

    return NULL;

}

void CLL::addAfter(node *ptr, int item){
    if(ptr==NULL)
        return;
    node *newNode = new node(item);
    newNode->next = ptr->next;
    ptr->next = newNode;
    if(ptr==last)
        last = newNode;

}

void CLL::deleteFirst(){
    if(isEmpty()){
        cout<<"Cannot delete from empty List"<<endl;
        return;
    }
    node *temp = last->next;
    if(temp == last)
        last = NULL;
    else
        last = last->next->next;
    delete temp;
}

void CLL::deleteLast(){
    if(isEmpty()){
        cout<<"Cannot delete from empty List"<<endl;
        return;
    }
    node *temp = last;
    while(temp->next!=last)
        temp = temp->next;
    if(temp == last){
        delete last;
        last = NULL;
    }
    else{
        temp->next = last->next;
        delete last;
        last = temp;
    }
}

void CLL::deleteNode(node *ptr){
    if(ptr==NULL)
        return;
    if(ptr==last)
        deleteLast();
    else{
        node *del = ptr->next;
        ptr->item = ptr->next->item;
        ptr->next = ptr->next->next;
        if(del == last)
            last = ptr;
        delete del;
    }
}
 