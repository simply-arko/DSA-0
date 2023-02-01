#include<iostream>
#include<stdio.h>   // for using NULL
using namespace std;

class node{
    public:
        int item;
        node *next;
        node(int item):item(item), next(NULL){}
};

class SLL{      // Singly-LinkedList

    private:
        node *start;

    public:
        SLL();
        SLL(const SLL&);
        ~SLL();
        node* getStart();
        void setStart(node*);
        bool isEmpty();
        void addFirst(int);
        void addLast(int);
        void addAfter(node*, int);
        node* linearSearch(int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
        void display();

};

SLL::SLL(){
    start = NULL;
}

SLL::SLL(const SLL &obj){
    start = obj.start;
}

SLL::~SLL(){
   while(start)
      deleteFirst();
}

node* SLL::getStart(){
    return start;
}

void SLL::setStart(node *ptr){
    start = ptr;
}

bool SLL::isEmpty(){
    return start==NULL;
}

void SLL::addFirst(int item){
    node *newNode = new node(item);
    newNode->next = start;
    start = newNode;
}

void SLL::addLast(int item){
    node *newNode = new node(item);
    if(isEmpty()){
        start = newNode;
        return;
    }
    node *temp = start;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newNode;
}

void SLL::addAfter(node *ptr, int num){
    if(ptr == NULL)
        return;
    node *newNode = new node(num);
    newNode->next = ptr->next;
    ptr->next = newNode;
}

node* SLL::linearSearch(int num){
    node *temp = start;
    while(temp)
        if(temp->item == num)
            return temp;
        else
            temp = temp->next;
    
    return NULL;
}

void SLL::deleteFirst(){
    if(isEmpty()){
        cout<<"Cannot delete from empty list!"<<endl;
        return;
    }
    node *temp = start;
    start = start->next;
    delete temp;
}

void SLL::deleteLast(){
    if(isEmpty()){
        cout<<"Cannot delete from empty list!"<<endl;
        return;
    }
    node *temp = start;
    if(temp->next == NULL){
        delete start;
        start = NULL;
        return;
    }
    while(temp->next->next!=NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void SLL::deleteNode(node *ptr){
    if(isEmpty()){
        cout<<"Cannot delete from empty list!"<<endl;
        return;
    }
    if(ptr == start){
        deleteFirst();
        return;
    }
    node *temp = start;
    while(temp->next != ptr)
        temp = temp->next;
    temp->next = ptr->next;
    delete ptr;
}

void SLL::display(){
    if(isEmpty()){
        cout<<"[]"<<endl;
        return;
    }
    node *temp = start;
    cout<<"[";
    do{
        cout<<temp->item<<" -> ";
        temp = temp->next;
    }while(temp);
    cout<<"NULL]"<<endl;
}

