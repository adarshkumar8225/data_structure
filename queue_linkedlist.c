#include<stdio.h>
#include<stdlib.h>
struct Listnode
{
	int data;
	struct Listnode *next;
};
void enqueue(struct Listnode **front,int data);
void dequeue(struct Listnode **front);
void display(struct Listnode **front);
int main()
{
	struct Listnode *front;
	int data,choice;
	front=NULL;
 while(1)
 {
 
	printf("press 1 for enqueue press 2 for dequeue press 3 to display:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\n printf enter the data:");
			scanf("%d",&data);
			enqueue(&front,data);
		break;
		case 2:
			dequeue(&front);
		break;
		case 3:
			display(&front);
		break;
		default :
			printf("\ninvalid input\n");
		break;
	}
 }
 return 0;
}

void enqueue(struct Listnode **front,int data)
{
	struct Listnode *newnode,*trav;
	trav=(*front);
	newnode=(struct Listnode *)malloc(sizeof(struct Listnode));
	newnode->data=data;
	newnode->next=NULL;
	if(trav==NULL)
	{
		(*front)=newnode;
	}
	else
	{
		while(trav->next!=NULL)//here u had taken only trav so only one element was printed so trav->next is taken. 
		{
			trav=trav->next;
		}
		trav->next=newnode;
	}
}

void dequeue(struct Listnode **front)
{
	
	struct Listnode *temp;
	temp=(*front);
	if(temp==NULL) printf("queue is empty\n");
	else
	(*front)=(*front)->next;
}

void display(struct Listnode **front)
{
	struct Listnode *trav;
	trav=*front;
	while(trav!=NULL)
	{
		printf("%d->",trav->data);
		trav=trav->next;
	}
	printf("\n");
}
