#include<iostream>
#include<vector>
using namespace std;

int partition(vector <int> &arr, int l, int r){
    int pivotIdx = l;  // taking pivot element as the first element

    for(int j=l+1; j<=r; j++)
        if(arr[j]<=arr[l])
            swap(arr[++pivotIdx], arr[j]);
    swap(arr[l], arr[pivotIdx]);
    return pivotIdx;
}

void quick_sort(vector <int> &arr, int l, int r){
        if(l>=r) return;
        
        int pivotIdx = partition(arr, l, r);
        quick_sort(arr, l, pivotIdx-1);
        quick_sort(arr, pivotIdx+1, r);
}

int main(){
    vector <int> arr = {20,12,35,16,18,30};
    cout<<"[";
    for(int x:arr)
        cout<<x<<", ";
    cout<<"]"<<endl;

    quick_sort(arr, 0, arr.size()-1);

    cout<<"[";
    for(int x:arr)
        cout<<x<<", ";
    cout<<"]"<<endl;

    return EXIT_SUCCESS;
}