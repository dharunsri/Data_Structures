#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    unsigned capacity;
    char* array;
};

struct stack* createStack(unsigned capacity){
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

void push(struct stack* stack, char data){
    stack->array[++stack->top] = data;

}

char pop(struct stack* stack){
    return stack->array[stack->top--];
}

void Reverse(char str[]){

    int n = strlen(str);
    struct stack* Stack = createStack(n);

    int i;
    for(i=0; i<n; i++)
        push(Stack, str[i]);

    for(i=0; i<n; i++)
        str[i] = pop(Stack);
}

int main(){
    char str[] = "TELUSKO";
    Reverse(str);
    printf("%s ",str);
    return 0;
}
