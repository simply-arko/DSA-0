#include<iostream>
#include<vector>
using namespace std;

class maxHeap{
    private:
        vector <int> heap;

    protected:
        void heapify(int);
        void swap(int&, int&);
    
    public:
        maxHeap();
        maxHeap(vector <int>);
        maxHeap(const maxHeap&);
        bool isEmpty();
        int heapSize();
        void insert(int);
        int get_max();
        void del_max();
        void display();
        vector <int> getHeap();
        maxHeap operator=(const maxHeap &obj){
            this->heap = obj.heap;
            return *this;
        }
};

maxHeap::maxHeap(){}

maxHeap::maxHeap(vector <int> v){
    heap = v;
    for(int i=(heapSize()/2)-1; i>=0; i--)
        heapify(i);
}

maxHeap::maxHeap(const maxHeap &obj){
    this->heap = obj.heap;
}

bool maxHeap::isEmpty(){
    return heap.size()==0;
}

int maxHeap::heapSize(){
    return heap.size();
}

void maxHeap::swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void maxHeap::heapify(int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    if(l<=heapSize() && heap[l]>heap[largest])
        largest = l;
    if(r<=heapSize() && heap[r]>heap[largest])
        largest = r;
    if(largest!=i){
        swap(heap[i], heap[largest]);
        heapify(largest);
    }
}

void maxHeap::insert(int item){
    heap.push_back(item);
    int i = heapSize()-1;
    int parent = (i-1)/2;
    while(parent>=0 && heap[parent]<heap[i]){
        swap(heap[parent], heap[i]);
        i = parent;
        parent = (i-1)/2;
    }
}

int maxHeap::get_max(){
    if(isEmpty()){
        cout<<"Heap is Empty!\n";
        return -1;
    }
    return heap[0];
}

void maxHeap::del_max(){
    if(isEmpty()){
        cout<<"Heap is Empty!\n";
        return;
    }
    heap[0] = heap[heapSize()-1];
    heap.pop_back();
    heapify(0);
}

void maxHeap::display(){
    cout<<"Heap: [";
    for(int i=0; i<heapSize(); i++)
        (i==heapSize()-1)?cout<<heap[i]:cout<<heap[i]<<", ";
    cout<<"]\n";
}

vector <int> maxHeap::getHeap(){
    return this->heap;
}

// int main(){
//     // maxHeap h;
//     // h.insert(4);
//     // h.insert(1);
//     // h.insert(3);
//     // h.insert(2);
//     // h.insert(16);
//     // h.insert(9);
//     // h.insert(10);
//     // h.insert(14);
//     // h.insert(8);
//     // h.insert(7);
//     // h.display();

//     // h.del_max();
//     // h.del_max();
//     // h.del_max();
//     // h.display();

// }