#include "../Heap/maxHeap.cpp"

void heapSort(vector <int> &v){
    maxHeap h(v);
    for(int i=v.size()-1; i>=0; i--){
        v[i] = h.get_max();
        h.del_max();
    }
}

int main(){
    vector <int> v = {4,1,3,2,16,9,10,14,8,7};
    heapSort(v);

    for(int x:v)
        cout<<x<<", ";

    return EXIT_SUCCESS;
}