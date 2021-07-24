#include<stdlib.h>
#include<stdio.h>
#define MAX 101
int stack[MAX];

int top = -1;

void push(int x){
    if(top==MAX-1){
        printf("Error: Overflow");
    }
    else{
        stack[++top] = x;
        return;
    }

}

void pop(){
    if(top==-1){
        printf("Error: Underflow - Stack is empty");
    }
    else{
        printf("%d is popped out ", stack[top]);
        top -= 1;
        return;
    }

}

void print(int stack[]){
    for(int i = top;i>=0;i--){
        printf("%d ",stack[i]);
    printf("\n");
    }
}

void Top(){
    printf("%d ", stack[top]);
}

int main(){
    int x;
    push(40);
    push(49);
    Top();
    push(33);
    pop();
    push(32);
    print(stack);
}
