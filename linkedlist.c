#include<stdio.h>
#include<stdlib.h>
struct Listnode 
{
	int data;
	struct Listnode *next;
};
void delete_node(struct Listnode **head,int position);
void insert_node(struct Listnode **head,int data,int position);


int main()
{
	struct Listnode *head,*trav,*newnode;
	int count=0,size,loc,newdata,position;
	char c[3];
	head=(struct Listnode *)malloc(sizeof(struct Listnode));
	printf("enter the first element:\t");
	scanf("%d",&head->data);
	head->next=NULL;
	trav=head;
//	printf("the element is :%d",head->data);


while(1)
{
	printf("if you want to enter more element press yes else press no:\n");
	scanf("%s",&c);
	if(strcmp(c,"yes")==0)
	{
	    newnode=(struct Listnode *)malloc(sizeof(struct Listnode));	
	    printf("enter the element:\n");
	    scanf("%d",&newnode->data);//yaha galti krta hai tu ampersand k symbol me
	    newnode->next=NULL;
	    while(trav->next!=NULL)
	    {
	    	trav=trav->next;
		}
		trav->next=newnode;
	}
	else if(strcmp(c,"no")==0)
	{
		break;
	}
	else 
	{
		printf("invalid input \n");
		break;
	}
	
}


trav=head;
while(trav!=NULL)
{
	printf("%d\t",trav->data);
	trav=trav->next;
	count++;
}


size=count;//no. of nodes in linked list.
printf("no. of nodes in the linked list are:%d\n",size);
printf("enter the position of node which u want to delete:");
scanf("%d",&loc);



delete_node(&head,loc);//calling of delete node function.


printf("elements remaining after deleting node number %d:\n",loc);


trav=head;
while(trav!=NULL)
{
	printf("%d\t",trav->data);
	trav=trav->next;
	count++;
}
printf("\n");
printf("enter the data and position where u want to insert new node:\n");
scanf("%d %d",&newdata,&position);


insert_node(&head,newdata,position);//calling of insert node function.

printf("the final elements after deletion and insertion at corresponding location:\n");


trav=head;
while(trav!=NULL)
{
	printf("%d\t",trav->data);
	trav=trav->next;
	count++;
}

	return 0;
}



//function to delete the specified number of node.
void delete_node(struct Listnode **head,int position)
{
	int count=1;
	struct Listnode *trav;
	trav=*head;
	if(position==1)//delete node at the beginning of list.
	{
		*head=(*head)->next;
	}
	else//delete the node at specified location.
	{
		while(count<(position-1))
		{
			trav=trav->next;
			count++;
		}
		trav->next=trav->next->next;
	}
}
//function to add a new node at specified location


void insert_node(struct Listnode **head,int newdata,int position)
{
	int count=2;
	struct Listnode *trav,*temp;
	trav=*head;
	temp=(struct Listnode *)malloc(sizeof(struct Listnode));
	temp->data=newdata;
	temp->next=NULL;
	if(position==1)//condition for inserting node at begining.
	{
		temp->next=*head;
		*head=temp;
		trav=*head;
	}
	else//inserting node at positions other then starting position.
	{
		while(count<position)
		{
			trav=trav->next;
			count++;
		}
		temp->next=trav->next;
		trav->next=temp;
	}
}
