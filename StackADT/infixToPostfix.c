#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(int x){
    stack[++top] = x;
}

// here I'm giving pop() the power to return popped element!
char pop(){
    return (top==-1)?-1:stack[top--];
}

int priority(char c){
    if(c=='(')
        return 0;
    else if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else
        return 0;
}

int main(){
    char exp[50];
    char *e, x;
    printf("Enter expression: ");
    scanf("%s", exp);
    e = exp;

    printf("Post-Fix expression: ");
    while(*e!='\0'){
        if(isalnum(*e))
            printf("%c", *e);
        else if(*e=='(')
            push(*e);
        else if(*e==')')
            while((x = pop())!='(')
                printf("%c", x);
        else{
            while(priority(*e)<=priority(stack[top]))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }

    while(top!=-1)
        printf("%c", pop());

    return 0;
}