#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverse(string exp){
    string rev;
    string::iterator ch;

    for(ch=exp.end(); ch!=exp.begin(); ch--)
        if(*ch==')')
            rev += '(';
        else if(*ch=='(')
            rev += ')';
        else
            rev += *ch;
    
    rev += *ch;
    return rev;
}

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

string infixToPrefix(string exp){
    
    string rev_exp = reverse(exp);
    string post_exp = infixToPostfix(rev_exp);
    return reverse(post_exp);
}

int main(){

    string exp;
    cout<<"Enter Expression: ";
    cin>>exp;

    cout<<infixToPrefix(exp);

    return EXIT_SUCCESS;

}
