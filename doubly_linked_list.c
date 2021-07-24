#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node* head;

void InsertAtHead(int data){
  struct Node* new = (struct Node*)malloc(sizeof(new));
  new->data = data;
  new->prev = NULL;
  new->next = NULL;

  if(head == NULL){
    head = new;
    return;
  }
  struct Node* temp = head;
  temp->prev = new;
  new->next = temp;
  head = new;
}

void print(){
  struct Node* temp = head;
  while(temp!=NULL){
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("NULL");
  printf("\n");
}

int main(){
  head = NULL;
  InsertAtHead(4);
  print();
  InsertAtHead(7);
  print();
  //printf("<<<<<");
  InsertAtHead(3);
  print();
  InsertAtHead(5);
  print();
  return 0;
}
