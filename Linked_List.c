#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* head;

void InsertAtBeg(int data){
  struct Node* new = (struct Node*)malloc(sizeof(struct Node));
  new->data = data;
  new->next = head;
  head = new;
  return;
}

void InsertAtEnd(int data){
  struct Node* New = (struct Node*)malloc(sizeof(struct Node));

  New->data = data;
  New->next = NULL;

  if(head == NULL){
    head = New;
    return;
  }
  else{
    struct Node* temp = head;
    while(temp->next!=NULL){
      temp = temp->next;
    }
    temp->next = New;
    return;
  }
}

void InsertAtRandom(int data, int n){
  struct Node* new = (struct Node*)malloc(sizeof(struct Node));
  new->data = data;
  new->next = NULL;

  if(n == 1){
    new->next = head;
    head = new;
    return;
  }
  else{
    struct Node* temp = head;
    for(int i = 0; i<n-2; i++){
      temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
    return;
  }
}

void print(){
  struct Node* temp = head;
  while(temp!=NULL){
    printf("%d->",temp->data);
    temp = temp->next;
  }
  printf("NULL");
  printf("\n");
}

void delete(int pos){
  struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
  temp1 = head;

  if(pos == 1){
    head = temp1->next;
    free(temp1);
  }

  else{
    for(int i = 0; i<pos-2; i++){
      temp1 = temp1->next;
    }
    struct Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    return;
  }
}

void RecursivePrint(struct Node* temp){
  if(temp==NULL)
    return;
  printf("%d",temp->data);
  RecursivePrint(temp->next);
}

void ReverseRecursive(struct Node* x){
  if(x==NULL)
    return;
  ReverseRecursive(x->next);
  printf("%d", x->data);
}

void Reverse(){
  struct Node* current, *prev, *next;
  current = head;
  prev = NULL;

  while(current!=NULL){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}

int main(){
  head = NULL;
  int size,val,i,n;
  printf("1. Inserting Node at Beg \t 2. Inserting Node at End \t 3. Inserting Node at random position \n");
  printf("Enter your choice: ");
  scanf("%d", &n);
  if(n==1){
    printf("Insert Node at Beg \n");
    printf("Enter the size: ");
    scanf("%d",&size);

    for(i=0;i<size;i++){
      printf("Enter the data: ");
      scanf("%d",&val);
      InsertAtBeg(val);
    }
    print();
  }
  else if(n==2){
    printf("Insert Node at End \n");
    printf("Enter the size: ");
    scanf("%d",&size);

    for(i=0;i<size;i++){
      printf("Enter the data: ");
      scanf("%d",&val);
      InsertAtEnd(val);
    }
    RecursivePrint(head);
  }
  else if(n==3){
    printf("\n Insert Node at random position \n");
    printf("Enter the size: ");
    int pos;
    scanf("%d",&size);
    for(i=0;i<size;i++){
      printf("Enter the data: ");
      scanf("%d",&val);
      printf("Enter the position: ");
      scanf("%d",&pos);
      InsertAtRandom(val,pos);
    }
    print();
  }
  else if(n==4){
    printf("Insert Node at Beg \n");
    printf("Enter the size: ");
    scanf("%d",&size);

    for(i=0;i<size;i++){
      printf("Enter the data: ");
      scanf("%d",&val);
      InsertAtBeg(val);
    }
    print();
  }
    printf("Delete a node \n");
    printf("Enter the node to be deleted: ");
    scanf("%d",&n);
    delete(n);
    print();

    Reverse();
    ReverseRecursive(head);

    return 0;

}
