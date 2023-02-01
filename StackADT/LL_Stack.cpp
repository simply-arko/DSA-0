#include<iostream>
using namespace std;

class node{

    public:
        int data;
        node *next;

        node(int data):data(data), next(NULL){}
};

class Stack{

    private:
        node *top;
    
    public:
        Stack();
        ~Stack();
        bool isEmpty();
        void push(int);
        int peek();
        void pop();
};

Stack::Stack(){
    top = NULL;
}

Stack::~Stack(){
    while(top)
        pop();
}

bool Stack::isEmpty(){
    return (top == NULL);
}

void Stack::push(int data){
    node *newNode = new node(data);
    newNode->next = top;
    top = newNode;
}

int Stack::peek(){
    if(isEmpty()){
        cout<<"Stack underflow!"<<endl;
        return -1;
    }

    return top->data;

}

void Stack::pop(){
    if(isEmpty()){
        cout<<"Stack underflow!"<<endl;
        return;
    }
    
    node *del = top;
    top = top->next;
    
    delete del;
}