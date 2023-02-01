#include <iostream>
using namespace std;

class DynArray{

    private:
        unsigned int size;
        int lIndex;
        int *ptr;
        void doubleArray();
        void halfArray();

    public:
        DynArray(int);
        ~DynArray();
        bool isEmpty();
        bool isFull();
        bool isHalf();
        int count();
        int currentCap();
        void append(int num);
        void insert(int, int);
        void edit(int, int);
        void del(int);
        int getElement(int);
        int linearSearch(int);
        void display();
};

bool DynArray::isFull(){
    return (lIndex == size-1);
}

bool DynArray::isHalf(){
    return (lIndex<this->size/2 && this->size>1);
}

int DynArray::count(){
    return (lIndex+1);
}

void DynArray::doubleArray(){
    this->size *= 2;
    int *tempArr = new int[this->size];
    for(int i=0; i<=this->lIndex; i++)
        tempArr[i] = ptr[i];
    delete [] ptr;
    ptr = tempArr;
}

void DynArray::halfArray(){
    this->size /= 2;
    int *tempArr = new int[this->size];
    for(int i=0; i<=this->lIndex; i++)
        tempArr[i] = ptr[i];
    delete [] ptr;
    ptr = tempArr;
}

DynArray::DynArray(int size):size(size){
    if(size<=0){
        cout<<"Invalid Size!"<<endl;
        exit(EXIT_FAILURE);
    }
    ptr = new int[size];
    this->lIndex = -1;
}

DynArray::~DynArray(){
    delete [] ptr;
}

int DynArray::currentCap(){
    return this->size;
}

bool DynArray::isEmpty(){
    return (lIndex == -1);
}

void DynArray::append(int num){
    if(isFull())
        doubleArray();
    ptr[++lIndex] = num;
}

void DynArray::insert(int index, int num){
    if(index<0 || index>lIndex+1){
        cout<<"Invalid index"<<endl;
        return;
    }
    else{
        if(isFull())
            doubleArray();
        for(int i=lIndex; i>=index; i--)
            ptr[i+1] = ptr[i];
        ptr[index] = num;
        lIndex++;
    }
}

void DynArray::edit(int index, int num){
    if(index<0 || index>lIndex){
        cout<<"Invalid index!!"<<endl;
        return;
    }
    else
        ptr[index] = num;
}

void DynArray::del(int index){
    if(isEmpty()){
        cout<<"Cannot delete from empty array!!"<<endl;
        return;
    }
    else if(index<0 || index>lIndex){
        cout<<"Invalid index!!"<<endl;
        return;
    }
    else{
        for(int i=index; i<lIndex; i++)
            ptr[i] = ptr[i+1];
        lIndex--;
        if(isHalf())
            halfArray();
    }
}

int DynArray::getElement(int index){
    if(isEmpty()){
        cout<<"Array is Empty"<<endl;
        return -1;
    }
    else if(index<0 || index>lIndex){
        cout<<"Invalid index!"<<endl;
        return -1;
    }
    return ptr[index];
}

int DynArray::linearSearch(int num){
    for(int i=0; i<num; i++)
        if(ptr[i] == num)
            return i;
    
    return -1;
}

void DynArray::display(){
    cout<<"[";
    for(int i=0; i<=lIndex; i++)
        if(i==lIndex)
            cout<<ptr[i];
        else
            cout<<ptr[i]<<", ";
    cout<<"]"<<endl;
}


int main(){

    DynArray arr(5);

    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.append(4);
    arr.append(5);
    arr.append(6);
    arr.append(7);
    arr.append(8);
    arr.append(9);
    arr.append(10);
    arr.append(10);
    arr.append(12);
    arr.append(13);
    

    arr.display();
    cout<<arr.count()<<endl;

    return EXIT_SUCCESS;
}