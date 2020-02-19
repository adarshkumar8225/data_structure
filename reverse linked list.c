#include<stdio.h>
#include<stdlib.h>
struct Listnode
{
	int data;
	struct Listnode *next;
};
void create_node(struct Listnode **head,int data );//double pointer is used bcz the head node need to be modified each time we enter the element.
void reverse_list(struct Listnode **head);

int main()
{
	struct Listnode *head,*trav;
	head=NULL;
	int n,i,A[20];
	printf("enter the number of elements:\n");
	scanf("%d",&n);
	printf("enter the elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	for(i=0;i<n;i++)
	{
		create_node(&head,A[i]);//function call to create node for each element and store the value in corresponding node.
	}
	
	trav=head;
	while(trav!=NULL)
	{
		printf("%d\t",trav->data);
		trav=trav->next;
	}
	printf("\n");
	
	reverse_list(&head);//function call to reverse the linked list.
	
	printf("elements after reversing the linked list:");
	trav=head;
	while(trav!=NULL)
	{
		printf("%d\t",trav->data);
		trav=trav->next;
	}
return 0;	
}


//function to create a new node in the linked list.
void create_node(struct Listnode **head,int data)
{
	struct Listnode *trav,*newnode;
		newnode=(struct Listnode *)malloc(sizeof(struct Listnode));
		newnode->data=data;
		newnode->next=NULL;
	//trav=*head;
	if(*head==NULL)
	{

		*head=newnode;
	   	 trav=*head;
	}
	
	else
	{
		while(trav->next!=NULL)
		{
			trav=trav->next;
		}
		trav->next=newnode;//here i was putting the address in trav so it was printing only first elements the i put the address in trav->next. 
	}
}

//function to reverse the linked list
void reverse_list(struct Listnode **head)
{
	struct Listnode *current,*prev,*next;
	current=*head;
	prev=NULL;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	*head=prev;//this is done so that head can point to the last node thus reverse the linked list.
}
