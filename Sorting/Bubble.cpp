#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a=b;
    b=temp;
}

void bubble_sort(vector <int> &A){
    int n = A.size();
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(A[j]>A[j+1])
                swap(A[j], A[j+1]);
}