#include<iostream>
using namespace std;

// implementing by Singly Linked-List

class node{

    public:
        int item;
        node* next;

        node(int item):item(item), next(NULL){}
};

class Queue{

    private:
        node *front;
        node *rear;

    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void enqueue(int);
        void dequeue();
        int peek_rear();
        int peek_front();
        int count();
        void display();
        void sort_assending();
        void sort_descending();

};

Queue::Queue(){
    front = rear = NULL;
}

Queue::~Queue(){
    while(front)
        dequeue();
}

bool Queue::isEmpty(){
    return (front==NULL&&rear==NULL);
}

void Queue::enqueue(int item){
    node *newNode = new node(item);
    if(isEmpty())
        front = rear = newNode;
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

void Queue::dequeue(){
    if(isEmpty()){
        cout<<"Queue is already empty!"<<endl;
        return;
    }
    else if(front==rear){
        delete front;
        front = rear = NULL;
    }
    else{
        node *del = front;
        front = front->next;
        delete del;
    }
}

int Queue::peek_front(){
    if(isEmpty()){
        cout<<"Queue is already empty!"<<endl;
        return -1;
    }
    else
        return front->item;
}

int Queue::peek_rear(){
    if(isEmpty()){
        cout<<"Queue is already empty!"<<endl;
        return -1;
    }
    else
        return rear->item;
}

int Queue::count(){
    int count = 0;
    node *temp = front;
    while(temp){
        temp = temp->next;
        count++;
    }

    return count;
}

void Queue::display(){
    cout<<"[";
    node *temp = front;
    while(temp){
        if(temp->next)
            cout<<temp->item<<"<-";
        else
            cout<<temp->item;
        temp = temp->next;
    }
    cout<<"]"<<endl;

}

void Queue::sort_assending(){
    if(isEmpty()){
        cout<<"Can't sort empty list!\n";
        return;
    }
    // Insertion sort

    node *dummy = new node(0);
    dummy->next = front;
    while(front->next){
        node *temp = dummy;
        while(front->next->item>temp->next->item)
            temp = temp->next;
        if(temp==front)
            front = front->next;
        else{
            node *m = front->next;
            front->next = front->next->next;
            m->next = temp->next;
            temp->next = m;
        }
    }

    front = dummy->next;
}

void Queue::sort_descending(){

    if(isEmpty()){
        cout<<"Can't sort empty list!\n";
        return;
    }
    // Insertion sort

    node *dummy = new node(0);
    dummy->next = front;
    while(front->next){
        node *temp = dummy;
        while(front->next->item<temp->next->item)
            temp = temp->next;
        if(temp==front)
            front = front->next;
        else{
            node *m = front->next;
            front->next = front->next->next;
            m->next = temp->next;
            temp->next = m;
        }
    }

    front = dummy->next;

}

int main(){
    Queue q;
    q.enqueue(2);
    q.enqueue(1);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(5);
    q.display();

    q.sort_assending();

    q.display();

    q.sort_descending();
    q.display();
    cout<<q.peek_front()<<endl;
    cout<<q.peek_rear()<<endl;


    return EXIT_SUCCESS;
}