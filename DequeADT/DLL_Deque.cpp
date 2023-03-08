#include<iostream>
using namespace std;

class node{

    public:
        int item;
        node *next;
        node *prev;

        node(int item):item(item), next(NULL), prev(NULL){}

};

class Deque{

    private:
        node *start;
        node *rear;

    public:
        Deque();
        ~Deque();
        bool isEmpty();
        void push_front(int);
        void push_back(int);
        void pop_front();
        void pop_back();
        int front();
        int back();
        void display();

};

Deque::Deque(){
    start = rear = NULL;
}

Deque::~Deque(){
    while(start)
        pop_front();
}

bool Deque::isEmpty(){
    return (start==NULL);
}

void Deque::push_front(int item){
    node *newNode = new node(item);
    if(isEmpty())
        start = rear = newNode;
    else{
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
    }
}

void Deque::push_back(int item){
    node *newNode = new node(item);
    if(isEmpty())
        start = rear = newNode;
    else{
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
}

void Deque::pop_front(){
    if(isEmpty())
        cout<<"Can't pop from empty list!\n";
    else if(start==rear){
        delete start;
        start = rear = NULL;
    }
    else{
        node *del = start;
        start = start->next;
        start->prev = NULL;
        delete del;
    }
}

void Deque::pop_back(){
    if(isEmpty())
        cout<<"Can't pop from empty list!\n";
    else if(start==rear){
        delete start;
        start = rear = NULL;
    }
    else{
        node *del = rear;
        rear = rear->prev;
        rear->next = NULL;
        delete del;
    }
}

int Deque::front(){
    if(isEmpty()){
        cout<<"List is Empty!\n";
        return -1;
    }

    return start->item;
}

int Deque::back(){
    if(isEmpty()){
        cout<<"List is Empty!\n";
        return -1;
    }

    return rear->item;
}

void Deque::display(){
    cout<<"[";
    node *temp = start;
    while(temp){
        if(temp==rear)
            cout<<temp->item;
        else
            cout<<temp->item<<"<->";
        temp = temp->next;
    }
    cout<<"]\n";
}