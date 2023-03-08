#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a=b;
    b=temp;
}

void selection_sort(vector <int> &A){
    int n = A.size();
    for(int i=0; i<n-1; i++){
        int minI = i;
        for(int j=i+1; j<n; j++)
            if(A[j]<A[minI])
                minI = j;
        if(minI!=i)
            swap(A[i], A[minI]);
    }
}

