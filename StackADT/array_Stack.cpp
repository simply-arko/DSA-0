#include<iostream>
using namespace std;

class Stack{

    private:
        int capacity;
        int top;
        int *ptr;
    
    public:
        Stack(int);
        Stack(const Stack &);
        ~Stack();
        int getCapacity(){return this->capacity;}
        bool isOverflow();
        bool isUnderflow();
        void push(int);
        void pop();
        int peek();
        void display();

        Stack& operator=(const Stack &);

};

Stack::Stack(int capacity):capacity(capacity){
    ptr = new int(capacity);
    top = -1;
}
Stack::~Stack(){
    delete ptr;
}

Stack::Stack(const Stack &obj){
    cout<<"Copy Constructor called!"<<endl;
    this->capacity = obj.capacity;
    this->top = obj.top;
    this->ptr = new int(this->capacity);
    for(int i=0; i<top; i++)
        ptr[i] = obj.ptr[i];

}

Stack& Stack::operator=(const Stack &obj){
    cout<<"Assignment operator called!"<<endl;
    this->capacity = obj.capacity;
    this->top = obj.top;
    for(int i=0; i<top; i++)
        this->ptr[i] = obj.ptr[i];

    return *this;
    
}

bool Stack::isOverflow(){
    return (top == capacity-1);
}

bool Stack::isUnderflow(){
    return (top==-1);
}

void Stack::push(int num){
    if(isOverflow()){
        cout<<"Stack overflow!"<<endl;
        return;
    }

    ptr[++top] = num;;
}

void Stack::pop(){
    if(isUnderflow()){
        cout<<"Stack underFlow!"<<endl;
        return;
    }
    top--;
}

int Stack::peek(){
    if(isUnderflow()){
        cout<<"Stack underFlow!"<<endl;
        return -1;
    }

    return ptr[top];
}

void Stack::display(){
    cout<<"[";
    for(int i=0; i<=top; i++)
        if(i==top)
            cout<<ptr[i];
        else
            cout<<ptr[i]<<"->";
    cout<<"]"<<endl;
}

