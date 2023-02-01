#include<iostream>
#include<stdio.h>
using namespace std;

class node{

    public:
        int item;
        node* next;
        node* prev;

        node(int item):item(item), next(NULL), prev(NULL){}
};

class CDLL{     // Circlular Doubly Linked-List

    private:
        node *start;

    public:
        CDLL();
        ~CDLL();
        bool isEmpty();
        void addFirst(int);
        void addLast(int);
        node* linearSearch(int);
        void addAfter(node*, int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
};

CDLL::CDLL(){
    start = NULL;
}

CDLL::~CDLL(){
    while(start)
        deleteFirst();
}

bool CDLL::isEmpty(){
    return (start == NULL);
}

void CDLL::addFirst(int item){
    addLast(item);
    start = start->prev;
}

void CDLL::addLast(int item){
    node *newNode = new node(item);
    if(isEmpty()){
        start = newNode;
        start->next = start;
        start->prev = start;
        return;
    }
    newNode->next = start;
    newNode->prev = start->prev;
    start->prev->next = newNode;
    start->prev = newNode;
}

node* CDLL::linearSearch(int item){
    if(isEmpty()){
        cout<<"List is Empty!"<<endl;
        return;
    }
    node* temp = start;
    do{
        if(temp->item == item)
            return temp;
        temp = temp->next;
    }while(temp!=start);

    return NULL;
}

void CDLL::addAfter(node *ptr, int item){
    if(ptr==NULL)
        return;
    node *newNode = new node(item);
    newNode->next = ptr->next;
    newNode->prev = ptr;
    ptr->next->prev = newNode;
    ptr->next = newNode;
    
}

void CDLL::deleteFirst(){
    if(isEmpty()){
        cout<<"Cannot delete from emty list!"<<endl;
        return;
    }
    node *del = start;
    if(del->next == start)
        start = NULL;
    else{
        start->next->prev = start->prev;
        start->prev->next = start->next;
        start = start->next;
    }
    delete del;
}

void CDLL::deleteLast(){
    if(isEmpty()){
        cout<<"Cannot delete from emty list!"<<endl;
        return;
    }
    node *del = start->prev;
    if(del == start)
        start = NULL;
    else{
        del->prev->next = start;
        start->prev = del->prev;
    }
    delete del;
}

void CDLL::deleteNode(node *ptr){
    if(ptr==NULL)
        return;

    if(ptr == start)
        deleteFirst();
    else{
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
    }
}
