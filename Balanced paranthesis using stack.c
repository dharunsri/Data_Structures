#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

struct Stack{
    char arr[MAX];
    int top;
}s;

//s.top = -1;

void push(char item){
    if(s.top == MAX-1){
        printf("Stack Overflow");
    }
    else{
        s.top = s.top+1;
        s.arr[s.top] = item;
        return;
    }
}

char pop(){
    if(s.top == -1){
        printf("Stack Underflow");
    }
    else{
        s.top = s.top-1;
        return s.top;
    }
}

int check(char exp[]){
    int i;
    char temp;
    for(i=0; i<strlen(exp);i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            push(exp[i]);
           }
        if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            //printf(">>>>");
            if(s.arr[s.top] == '(' && exp[i] == ')'){
                pop();
            }
            if(s.arr[s.top] == '[' && exp[i] == ']')
                pop();
            if(s.arr[s.top] == '{' && exp[i] == '}')
                pop();
        }
    }
    if(s.top==-1){
        printf("Balanced Parantheses");
        return 1;
    }
    else{
        printf("Unbalanced Parantheses");
        return 0;
    }
}

int main(){
    char exp[MAX];
    s.top = -1;
    printf("Enter the expression: ");
    gets(exp);
    check(exp);
    return 0;
}
