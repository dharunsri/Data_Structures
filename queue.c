#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int a[10];
int front = -1;
int rear = -1;


void Enqueue(int x){
	if(rear == sizeof(a)-1)
		return;
	else if(front == -1 && rear == -1){
		front = rear = 0;
		return;
	}
	a[rear++] = x;
}

void Dequeue(){
	if(front == -1 && rear == -1)
		return;
	else if(front == rear)
		front = rear = -1;
	else
		front += 1;
}

void Print(){
	for(int i = front; i<rear; i++){
		printf("%d ", a[i]);
	}
}

int main(void)
{
	Enqueue(20);
	Enqueue(90);
	Enqueue(1);
	Enqueue(123);
	Enqueue(14);
	Enqueue(11);
	Enqueue(15);
	Dequeue();
	Dequeue();
	Print();
	return 0;
}