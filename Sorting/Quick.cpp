#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector <int> &A, int p, int q){
    int i = p;
    for(int j=p+1; j<=q; j++)
        if(A[j]<=A[p])
            swap(A[++i], A[j]);
    swap(A[p], A[i]);
    return i;
}

void quick_sort(vector <int> &A, int p, int r){
    if(p<r){
        int q = partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}
