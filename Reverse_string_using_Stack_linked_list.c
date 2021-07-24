#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    char data;
    struct Stack* next;
};

struct Stack* top = NULL;
struct Stack* head = NULL;

void Push(char data){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->data = data;
    stack->next = top;
    top = stack;
    return;

}

char pop(){
    struct Stack* temp = top;
    top = top->next;
    return temp->data;
    free(temp);
}

void Reverse(char str[]){
    int n = strlen(str);

    for(int i=0; i<n; i++)
        Push(str[i]);

    for(int i=0; i<n; i++)
        str[i] = pop();
}

int main(){
    char str[] = "TELUSKO";
    Reverse(str);
    printf("%s ", str);
    return 0;
}
