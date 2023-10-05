#include<iostream>
#include<vector>
using namespace std;

void merge(vector <int> &arr, int l, int mid, int r){

    int leftLength = mid-l+1;
    int rightLength = r-mid;
    int leftSubarray[leftLength], rightSubarray[rightLength];

    for(int i=0; i<leftLength; i++)
        leftSubarray[i] = arr[l+i];
    for(int i=0; i<rightLength; i++)
        rightSubarray[i] = arr[mid+1+i];
    
    int i=0;    // pointer to left sub-array
    int j=0;    // pointer to right sub-array
    int k=l;    // pointer to main-array
    while(i<leftLength && j<rightLength)
        arr[k++] = (leftSubarray[i]<rightSubarray[j])?leftSubarray[i++]:rightSubarray[j++];
    
    // incase i's journey is left
    while(i<leftLength)
        arr[k++] = leftSubarray[i++];
    // incase j's journey is left
    while(j<rightLength)
        arr[k++] = rightSubarray[j++];

}

void merge_sort(vector <int> &arr, int l, int r){
    if(l>=r)
        return;

    int mid = (l+r)/2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

int main(){
    vector <int> arr = {10,28,24,6,34,18,38,44};
    cout<<"[";
    for(int x:arr)
        cout<<x<<", ";
    cout<<"]"<<endl;

    merge_sort(arr, 0, arr.size()-1);

    cout<<"[";
    for(int x:arr)
        cout<<x<<", ";
    cout<<"]"<<endl;

    return EXIT_SUCCESS;
}