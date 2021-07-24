#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev
};

struct Node* head;

void InsertAtHead(int data){
    struct Node* new = (struct Node*)malloc(sizeof(new));
    new->data = data;

    if(head == NULL){
        new->next = new;
        new->prev = new;
        head = new;
        return;
    }
    else{
        struct Node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        new->next = head;
        new->prev = temp;
        temp->next = new;
        head->prev = new;
        head = new;
        return;

    }
}

void InsertAtEnd(int data){
    struct Node* new = (struct Node*)malloc(sizeof(new));
    new->data = data;

    if(head == NULL){
        new->next = new;
        new->prev = new;
        head = new;
        return;
    }

    struct Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = new;
    new->next = head;
    head->prev = new;
    new->prev = temp;
    return;
}

void InsertRandom(int data, int n){
    struct Node* new = (struct Node*)malloc(sizeof(new));
    new->data = data;

    if(head == NULL){
        new->next = new;
        new->prev = new;
        head = new;
        return;
    }
    if(n == 1){
        struct Node* temp1 = head;
        while(temp1->next!=head){
            temp1 = temp1->next;
        }
        new->next = head;
        temp1->next = new;
        new->prev = temp1;
        head->prev = new;
        head = new;
        return;
    }
    struct Node* temp = head;
    for(int i=0; i<n-2; i++){
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next->prev = new;
    temp->next = new;
    new->prev =temp;
    return;
}

void Reverse(){
    struct Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    do{
        printf("%d->",temp->data);
        temp = temp->prev;
    }while(temp!=head);
    printf("%d->", temp->data);
    printf("\n");
}

void Recursive(struct Node* temp){
    if(temp->next == head ){
        printf("%d->",temp->data);
        return;
    }
    printf("%d->", temp->data);
    Recursive(temp->next);
}

void RecursiveReverse(struct Node* temp){

    if(temp->next == head){
        printf("%d->",temp->data);
        return;
    }
    RecursiveReverse(temp->next);
    printf("%d->", temp->data);
}

void Delete(int pos){
    struct Node* current, *temp;
    temp = head;
    if(pos==1){
        current = temp->next;
        current->prev = temp->prev;
        temp->prev->next = current;
        free(temp);
        head = current;
        return;
    }
    for(int i=0; i<=pos-2; i++){
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return;
}

void Print(){
    struct Node* temp = head;
    do{
        printf("%d->",temp->data);
        temp = temp->next;
    }while(temp!=head);
    printf("\n");
}

int main(){
    head = NULL;
    InsertAtHead(5);
    InsertAtHead(4);
    InsertAtHead(1);
    Print();
    InsertAtEnd(7);
    InsertAtEnd(9);
    Print();
    InsertRandom(40,1);
    InsertRandom(50,3);
    Print();
    Reverse();
    Recursive(head);
    printf("\n");
    RecursiveReverse(head);
    printf("\n");
    Delete(1);
    Delete(2);
    Print();
    return 0;
}
