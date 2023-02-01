#include<iostream>
using namespace std;

class Queue{

    private:
        int capacity;
        int front;
        int rear;
        int *ptr;
    
    public:
        Queue(int);
        ~Queue();
        bool isEmpty();
        bool isFull();
        void enqueue(int);
        void dequeue();
        int peek_rear();
        int peek_front();
        int count();
        void display();

};

Queue::Queue(int capacity){
    this->capacity = capacity;
    ptr = new int[capacity];
    rear = front = -1;
}

Queue::~Queue(){
    delete ptr;
}

bool Queue::isEmpty(){
    return (rear==-1);
}

bool Queue::isFull(){
    return (rear>front)?(rear-front==capacity-1):(rear==front-1);
}

void Queue::enqueue(int item){
    if(isFull()){
        cout<<"Queue is Full!"<<endl;
        return;
    }
    if(isEmpty())
        front = 0;
    rear = (rear+1)%capacity;
    ptr[rear] = item;
}

void Queue::dequeue(){
    if(isEmpty()){
        cout<<"Queue is Empty!"<<endl;
        return;
    }
    if(front==0&&rear==0){
        front = rear = -1;
        return;
    }

    front = (front+1)%capacity;
    if(front==rear)
        front = rear = -1;
}

int Queue::peek_rear(){
    if(isEmpty()){
        cout<<"Queue is Empty!"<<endl;
        return -1;
    }

    return ptr[rear];
}

int Queue::peek_front(){
    if(isEmpty()){
        cout<<"Queue is Empty!"<<endl;
        return -1;
    }
    
    return ptr[front];
}

int Queue::count(){
    return (rear>front)?(rear-front+1):(capacity-(front-rear-1));
}

void Queue::display(){
    cout<<"[";
    if(!isEmpty()){
        if(rear>front)
            for(int i=front; i<=rear; i++)
                if(i==rear)
                    cout<<ptr[i];
                else
                    cout<<ptr[i]<<"<-";
        else{
            for(int i=front; i<=capacity-1; i++)
                cout<<ptr[i]<<"<-";
            for(int i=0; i<=rear; i++)
                if(i==rear)
                    cout<<ptr[i];
                else
                    cout<<ptr[i]<<"<-";
        }
    }

    cout<<"]"<<endl;
}

int main(){
    Queue q(5);
    q.display();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    cout<<q.count()<<endl;
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.display();
    cout<<q.count()<<endl;
    cout<<q.peek_front()<<endl;
    cout<<q.peek_rear()<<endl;

    q.display();
    
    return EXIT_SUCCESS;
}