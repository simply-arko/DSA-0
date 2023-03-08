#include<iostream>
#include<vector>
using namespace std;

void merge(vector <int> &arr, int p, int q, int r){

    int n1 = q-p+1, n2 = r-q;
    int L[n1+1], R[n2+1];
    for(int i=0; i<n1; i++)
        L[i] = arr[p+i];
    L[n1] = INT_MAX; 
    for(int i=0; i<n2; i++)
        R[i] = arr[q+1+i];
    R[n2] = INT_MAX;
    int i=0, j=0;
    for(int k=p; k<=r; k++)
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }

}

void merge_sort(vector <int> &arr, int p, int r){
    if(p<r){
        int q = (p+r)/2;
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

int main(){
    vector <int> arr = {8,7,6,5,4,3,2,1};
    cout<<"[";
    for(int x:arr)
        cout<<x<<", ";
    cout<<"]"<<endl;

    merge_sort(arr, 0, arr.size()-1);

    for(int x:arr)
        cout<<x<<", ";
    cout<<"]"<<endl;

    return EXIT_SUCCESS;
}