#include<stdio.h>
#include<stdlib.h>
void enqueue(int *A,int *front,int *rear,int data);
void dequeue(int *front,int *rear);
void display(int *A,int *front,int *rear);
int main()
{
	int A[10],front=-1,rear=-1,data,choice;
while(1)
{
	
	printf("press 1 for enqueue and press 2 for dequeue press 3 to display:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("enter the data:");
			scanf("%d",&data);
			enqueue(&A,&front,&rear,data);
		break;
		case 2:
			dequeue(&front,&rear);
		break;
		case 3:
			display(&A,&front,&rear);
		break;
		default:
			printf("invalid input:\n");
		break;
	}
}
	return 0;
}


void enqueue(int *A,int *front ,int *rear,int data)
{
	if(*rear>9) printf("queue is full so no more enqueue operation\n");
	else if((*rear)==-1 && (*front)==-1)
	{
		*rear=*rear+1;
		*front=*front+1;
		A[*rear]=data;
	}
	else
	{
		*rear=(*rear)+1;
		A[*rear]=data;
	}
}


void dequeue(int *front,int *rear)
{
	if((*front)==-1&&(*rear)==-1) printf("queue is empty\n");
	else if((*rear)==(*front))
	{
		*rear=(*front)=-1;
	}
	else
	{
		*front=(*front)+1;
	}
}
 void display(int *A,int *front,int *rear)
 {
 	int i;
 	for(i=(*front);i<(*rear);i++)
 	{
 		printf("%d<-",A[i]);
	 }
	 printf("%d",A[i]);
	 printf("\n");
 }
