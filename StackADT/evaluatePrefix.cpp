#include<iostream>
#include<string>
#include<stack>
using namespace std;

void swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}

void reverse(string &str){
    int l = 0, r = str.size()-1;
    while(l<r)
        swap(str[l++], str[r--]);
}

int evaluatePrefix(string exp){
    stack <int> st;
    reverse(exp);

    for(char ch:exp){
        if(ch=='+'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b+a);
        }
        else if(ch=='-'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b-a);
        }
        else if(ch=='*'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b*a);
        }
        else if(ch=='/'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b/a);
        }
        else
            st.push(ch-48);
    }
    
    return st.top();
}

int main(){

    string exp;
    cout<<"Enter prefix expression: ";
    cin>>exp;

    cout<<evaluatePrefix(exp);

}