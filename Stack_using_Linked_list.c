#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack* next;
};

struct stack* top = NULL;


void push(int data){
    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    temp->data = data;
    temp->next = top;
    top = temp;
    return;

}

void pop(){
    if(top == NULL)
        printf("Stack Underflow - No items to pop");
    struct stack* temp = top;
    printf("\n %d is popped out \n", top->data);
    top = top->next;
    free(temp);
    return;
}

void Top(){
    return top->data;
}

void Print(){
    struct stack* temp = top;
    while(temp!=NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\n");
}

int main(){
    push(200);
    push(100);
    push(100);
    Print();
    pop();
    push(250);
    push(105);
    Top();
    Print();

    return 0;
}
