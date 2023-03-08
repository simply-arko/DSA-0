#include<iostream>
#include<vector>
using namespace std;

void insertion_sort(vector <int> &arr){

    int size = arr.size();
    for(int i=1; i<size; i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }

}

int main(){
    vector <int> arr = {6,5,4,3,2,1};
    cout<<"[";
    for(int x:arr)
        cout<<x<<", ";
    cout<<"]"<<endl;

    insertion_sort(arr);

    for(int x:arr)
        cout<<x<<", ";
    cout<<"]"<<endl;

    return EXIT_SUCCESS;
}