#include<iostream>
#include<stdio.h>   // for using NULL
using namespace std;

class node{

    public:
        int data;
        node *next;
        node *prev;

        node(int data):data(data){}
};

class DLL{      // Doubly Linked-List

    private:
        node *start;

    public:
        DLL();
        ~DLL();
        bool isEmpty();
        void addFirst(int);
        void addLast(int);
        node* linearSearch(int);
        void insertAfter(node*, int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
}; 

DLL::DLL(){
    start = NULL;
}

DLL::~DLL(){
    while(start!=NULL)
        deleteFirst();
}

bool DLL::isEmpty(){
    return (start == NULL);
}

void DLL::addFirst(int data){
    node *newNode = new node(data);
    newNode->prev = NULL;
    newNode->next = start;
    if(!isEmpty())
        start->prev = newNode;
    start = newNode;
}

void DLL::addLast(int data){
    node *newNode = new node(data);
    newNode->next = NULL;
    if(isEmpty()){
        newNode->prev = NULL;
        start = newNode;
        return;
    }
    node *temp = start;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

node* DLL::linearSearch(int data){
    // Not required
    // if(isEmpty()){
    //     cout<<"List is empty!"<<endl;
    //     return NULL;
    // }
    node *temp = start;
    while(temp){
        if(temp->data == data)
            return temp;
        temp = temp->next;
    }
    cout<<"Item not present!"<<endl;
    return NULL;
}

void DLL::insertAfter(node *ptr, int data){
    if(ptr==NULL)
        return;
    node *newNode = new node(data);
    newNode->prev = ptr;
    newNode->next = ptr->next;
    if(ptr->next!=NULL)
        ptr->next->prev = newNode;
    ptr->next = newNode;
}

void DLL::deleteFirst(){
    if(isEmpty()){
        cout<<"Cannot delete from empty list!"<<endl;
        return;
    } 
    
    node *temp = start;
    if(start->next)
        start->next->prev = NULL;
    start = start->next;
    delete temp;

}

void DLL::deleteLast(){
    if(isEmpty()){
        cout<<"Cannot delete from empty list!"<<endl;
        return;
    }
    node *temp = start;
    while(temp->next!=NULL)
        temp = temp->next;
    if(temp->prev)
        temp->prev->next = NULL;
    else
        start = NULL;
    delete temp;

}

void DLL::deleteNode(node *ptr){
    if(ptr == NULL)
        return;
    else if(ptr == start)
        deleteFirst();
    else{
        ptr->prev->next = ptr->next;
        if(ptr->next)
            ptr->next->prev = ptr->prev;
        delete ptr;
    }
}