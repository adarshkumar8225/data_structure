#include<stdio.h>
#include<stdlib.h>
struct Linkedlist
{
	int data;
	struct Linkedlist *next;
};
void push(struct Linkedlist **top,int data);
void pop(struct Linkedlist **top);
void display(struct Linkedlist **top);
int main()
{
	struct Linkedlist *top;
	top=NULL;
	int choice,data;
  while(1)
   {

	printf("press 1 for push 2 for pop 3 for display:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\nenter the data:");
			scanf("%d",&data);
			push(&top,data);
		break;
		case 2:
			pop(&top);
		break;
		case 3:
			display(&top);
		break;
		default:
			printf("invalid input:\n");
		break;
	}
  }
  return 0;
}
void push(struct Linkedlist **top,int data)
{
	struct Linkedlist *temp,*newnode;
	temp=*top;
	newnode=(struct Linkedlist *)malloc(sizeof(struct Linkedlist));
	newnode->data=data;
	newnode->next=NULL;
	if(temp==NULL)
	{
		*top=newnode;
	}
	else
	{
		newnode->next=temp;
		*top=newnode;
	}
}

void pop(struct Linkedlist **top)
{
	//struct Linkedlist *temp;
	//temp=*top;
	if((*top)==NULL)  printf("stack is empty so no pop operation:\n");
	else (*top)=(*top)->next;
}
void display(struct Linkedlist **top)
{
	struct Linkedlist *trav;
	trav=*top;
	while(trav!=NULL)
	{
		printf("%d\n",trav->data);
		trav=trav->next;
	}
}
