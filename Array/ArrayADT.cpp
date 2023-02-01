#include <iostream>
using namespace std;

class Array{
    
    private:
        unsigned int size;
        int lIndex;
        int *ptr;

    public:
        Array(int);
        ~Array();
        bool isEmpty();
        bool isFull();
        int count();
        void append(int);
        void insert(int, int);
        void edit(int, int);
        void del(int);
        int getElement(int);
        short linearSearch(int);
        void display();
};

Array::Array(int size):size(size){
    // ptr = (int*)malloc(sizeof(int)*size);
    ptr = new int[size];
    this->lIndex = -1;
}

Array::~Array(){
    delete [] ptr;
}

bool Array::isEmpty(){
    return (lIndex == -1);
}

bool Array::isFull(){
    return (lIndex == size-1);
}

int Array::count(){
    return lIndex+1;
}

void Array::append(int num){
    if(isFull()){
        cout<<"Can't append in full array"<<endl;
        return;
    }
    ptr[++lIndex] = num;
}

void Array::insert(int index, int num){
    if(isFull()){
        cout<<"Array is already Full!"<<endl;
        return;
    }
    else if(index<0 || index>lIndex+1){
        cout<<"Cannot insert element"<<endl;
        return;
    }
    else{
        for(int i=lIndex; i>=index; i--)
            ptr[i+1] = ptr[i];
        ptr[index] = num;
        lIndex++;
    }
}

void Array::edit(int index, int num){
    if(index<0 || index>lIndex){
        cout<<"Invalid index"<<endl;
        return;
    }
    ptr[index] = num;
}

void Array::del(int index){
    if(isEmpty()){
        cout<<"Array is empty!"<<endl;
        return;
    }
    else if(index<0 || index>lIndex){
        cout<<"Invalid Index!"<<endl;
        return;
    }
    else{
        for(int i=index; i<lIndex; i++)
            ptr[i] = ptr[i+1];
        lIndex--;
    }
}

int Array::getElement(int index){
    if(isEmpty()){
        cout<<"Array is empty!"<<endl;
        return -1;
    }
    else if(index<0 || index>lIndex){
        cout<<"Invalid Index!"<<endl;
        return -1;
    }
    return ptr[index];
}

short Array::linearSearch(int num){
    for(int i=0; i<=lIndex; i++)
        if(ptr[i]==num)
            return i;
    
    return -1;
}

void Array::display(){
    cout<<"[";
    for(int i=0; i<=lIndex; i++)
        if(i==lIndex)
            cout<<ptr[i];
        else
            cout<<ptr[i]<<", ";
    cout<<"]"<<endl;
}
