#include<iostream>
#include<string>
#include<stack>
using namespace std;

int evaluatePostfix(string exp){
    stack <int> st;
    
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
    cout<<"Enter postfix expression: ";
    cin>>exp;

    cout<<evaluatePostfix(exp);

}