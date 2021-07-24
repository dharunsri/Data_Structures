#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void InsertAtHead(int data){
    struct Node* new = (struct Node*)malloc(sizeof(new));
    new->data = data;

    if(head == NULL){
        head = new;
        new->next = head;
        return;
    }
    struct Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    new->next = head;
    temp->next = new;
    head = new;
    return;
}

void InsertAtEnd(int data){
    struct Node* new = (struct Node*)malloc(sizeof(new));
    new->data = data;

    if(head == NULL){
        head = new;
        new->next = head;
    }
    struct Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = new;
    new->next = head;
}

void InsertRandom(int data, int n){
    struct Node* new = (struct Node*)malloc(sizeof(new));
    new->data = data;
    new->next = new;

    if(n == 1){
        //InsertAtHead(data);
        struct Node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        new->next = head;
        temp->next = new;
        head = new;
        return;
            //return;
    }
    struct Node* temp = head;
    for(int i=0; i<n-2; i++){
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;

}

void print(){
    struct Node* temp = head;

    do{
        printf("%d-> ",temp->data);
        temp= temp->next;
    }while(temp!=head);
}

void RecursiveReverse(struct Node* temp){
    if(temp->next==head){
        printf("%d ", temp->data);
        return;
    }
    RecursiveReverse(temp->next);
    printf("%d ",temp->data);
}

void Delete(int pos){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    struct Node* current = temp;
    if(pos == 1){
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
        return;
    }
    struct Node* temp2;
    for(int i=0; i<pos-2; i++){
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

void Reverse(){
    struct Node* current, *prev, *next;
    current = head;
    prev = NULL;

    do{
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    }while(current!=head);
    head = prev;

}

int main(){
    head = NULL;
    InsertAtHead(20);
    //print();
    InsertAtHead(10);
    //print();
    InsertAtEnd(100);
    InsertAtEnd(200);
    InsertAtEnd(222);
    InsertRandom(1000,1);
    InsertRandom(2000,2);
    //InsertRandom(2000,1);
    //InsertRandom(2000,4);
    print();
    printf("\n");
    Delete(1);
    Delete(6);
    print();
    printf("\n");
    RecursiveReverse(head);
    printf("\n");
    Reverse();
    print();
    return 0;
}
