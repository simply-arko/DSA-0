#include<iostream>
#include<stack>
#include<string>
using namespace std;

int priority(char ch){
    if(ch=='(')
        return 0;
    else if(ch=='+' || ch=='-')
        return 1;
    else
        return 2;
}

string infixToPostfix(string exp){
    string post;
    stack <char> st;

    for(char ch:exp){
        if(ch=='(')
            st.push(ch);
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            if(st.empty()){
                st.push(ch);
                continue;
            }
            while(priority(ch)<=priority(st.top())){
                post += st.top();
                st.pop();
                if(st.empty())
                    break;
            }
            st.push(ch);
        }
        else if(ch==')'){
            while(!st.empty()&&st.top()!='('){
                post += st.top();
                st.pop();
            }
            st.pop();
        }
        else
            post += ch;

        // cout<<post<<endl;
    }
    while(!st.empty()){
        post+=st.top();
        st.pop();
    }

    return post;
}

int main(){

    string exp;
    cout<<"Enter Expression: ";
    cin>>exp;

    cout<<infixToPostfix(exp);

    return EXIT_SUCCESS;


}