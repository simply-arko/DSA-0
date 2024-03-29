#include<iostream>
#include<vector>
using namespace std;

void counting_sort(vector <int> &A){
    int n = A.size();

    // finding max element:
    int max_element = A[0];
    for(int i=1; i<n; i++)
        max_element = max(max_element, A[i]);
    
    vector <int> freq(max_element+1, 0);
    for(int i=0; i<n; i++)
        freq[A[i]]++;
    
    // Calculating cumulative frequency:
    for(int i=1; i<=max_element; i++)
        freq[i] += freq[i-1];

    // ans Vector:
    vector <int> ans(n);
    for(int i=n-1; i>=0; i--)
        ans[--freq[A[i]]] = A[i];
    
    // copy back ans to original array:
    for(int i=0; i<n; i++)
        A[i] = ans[i];
    
}

int main(){
    vector <int> arr = {5,2,3,2,1};
    cout<<"[";
    for(int x:arr)
        cout<<x<<", ";
    cout<<"]"<<endl;

    counting_sort(arr);

    cout<<"[";
    for(int x:arr)
        cout<<x<<", ";
    cout<<"]"<<endl;

    return EXIT_SUCCESS;
}