#include<iostream>
using namespace std;

class node{
    
    public:
        int value;
        int key;
        node *next;

        node(int value, int key):value(value),key(key), next(NULL){}
};

class Priority_Queue{

    private:
        node *start;
    
    public:
        Priority_Queue();
        ~Priority_Queue();
        bool isEmpty();
        void insert(int, int);
        void delete_highest_priority();
        void delete_lowest_priority();
        int get_highest_priority();
        int get_lowest_priority();
        void display();
};

Priority_Queue::Priority_Queue(){
    start = NULL;
}

Priority_Queue::~Priority_Queue(){
    while(start)
        delete_lowest_priority();
}

bool Priority_Queue::isEmpty(){
    return (start==NULL);
}

void Priority_Queue::insert(int value, int key){
    node *newNode = new node(value, key);
    if(isEmpty())
        start = newNode;
    else if(start->key<key){
        newNode->next = start;
        start = newNode;
    }
    else{
        node *temp = start;
        while(temp->next&&temp->next->key>=key)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void Priority_Queue::delete_lowest_priority(){
    if(isEmpty())
        cout<<"Can't delete from empty queue!\n";
    else if(start->next==NULL){
        delete start;
        start = NULL;
    }
    else{
        node *temp = start;
        while(temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }
}

void Priority_Queue::delete_highest_priority(){
    if(isEmpty())
        cout<<"Can't delete from empty queue!\n";
    else{
        node *del = start;
        start = start->next;
        delete del;
    }
}

int Priority_Queue::get_lowest_priority(){
    if(isEmpty()){
        cout<<"Queue is Empty!\n";
        return -1;
    }
    else{
        node *temp = start;
        while(temp->next)
            temp = temp->next;
        return temp->value;
    }
}

int Priority_Queue::get_highest_priority(){
    if(isEmpty()){
        cout<<"Queue is Empty!\n";
        return -1;
    }
    else
        return start->value;
}

void Priority_Queue::display(){
    if(isEmpty()){
        cout<<"Empty Queue!\n";
        return;
    }
    node *temp = start;
    while(temp){
        if(temp->next)
            cout<<"["<<temp->key<<", "<<temp->value<<"]"<<"<->";
        else
            cout<<"["<<temp->key<<", "<<temp->value<<"]\n";
        temp = temp->next;
    }
}

int main(){
    Priority_Queue q;
    q.insert(23, 2);
    q.insert(21, 3);
    q.insert(32, 1);
    q.insert(29, 4);
    q.insert(40, 5);
    q.insert(42, 8);
    q.insert(41, 10);
    q.insert(69, 5);
    q.display();

    q.delete_highest_priority();
    q.display();

    q.delete_lowest_priority();
    q.display();

    cout<<q.get_highest_priority()<<", "<<q.get_lowest_priority()<<endl;

    return EXIT_SUCCESS;
}