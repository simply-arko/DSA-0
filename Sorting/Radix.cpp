#include<iostream>
#include<vector>
using namespace std;

void counting_sort(vector <int> &A, int pos){
    int n = A.size();
    
    vector <int> freq(10, 0);
    for(int i=0; i<n; i++)
        freq[(A[i]/pos)%10]++;
    
    // Calculating cumulative frequency:
    for(int i=1; i<10; i++)
        freq[i] += freq[i-1];

    // ans Vector:
    vector <int> ans(n);
    for(int i=n-1; i>=0; i--)
        ans[--freq[(A[i]/pos)%10]] = A[i];
    
    // copy back ans to original array:
    for(int i=0; i<n; i++)
        A[i] = ans[i];
    
}

void RadixSort(vector <int> &A){
    int n = A.size();

    // finding max element:
    int max_element = A[0];
    for(int i=1; i<n; i++)
        max_element = max(max_element, A[i]);

    for(int pos=1; max_element/pos>0; pos*=10)
        counting_sort(A, pos);

}

int main(){
    vector <int> arr = {170,45,75,90,802,2};
    cout<<"[";
    for(int x:arr)
        cout<<x<<", ";
    cout<<"]"<<endl;

    RadixSort(arr);

    cout<<"[";
    for(int x:arr)
        cout<<x<<", ";
    cout<<"]"<<endl;

    return EXIT_SUCCESS;
}