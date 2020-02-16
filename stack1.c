//stack using array
#include<stdio.h>
#include<stdlib.h>
void push(int *A,int data,int *top);//function to push element in stack
void pop(int *A,int *top);//function to pop element at the top of stack
int main()
{
	int A[20],top=-1,data,i;
	char c[5];
	printf("enter the first element you want to insert:");
	scanf("%d",&data);
	top++;
	A[top]=data;
	while(1)
	{
		printf("if u want to push type push or if u want to pop press pop finally type dsplay to get the elements of stack: ");
		scanf("%s",&c);
		if(strcmp(c,"push")==0)
		{
			printf("enter the element:");
			scanf("%d",&data);
			push(&A,data,&top);
		}
		else if(strcmp(c,"pop")==0) pop(&A,&top);
		else if(strcmp(c,"display")) break;
		else
		{
			printf("invalid input\n");
			break;
		}
	}
printf("elements after push and pop is:\n");
for(i=0;i<top+1;i++)
    {
    	printf("%d\n",A[top-i]);
	}
return 0;	
}

//function to push the element at the top of stack

void push(int *A,int data,int *top)
{
	
	*top=*top+1;
	A[*top]=data;//here *A[]is not used bcz we need only location to put the data we dont need the value.
	//*(A+*top)=data;
	
}

//function to pop the element from the top of stack.

void pop(int *A,int *top)
{
	if(*top==-1)
	{
		printf("stack is empty no further pop operation is possible\n");
	}
	else
	{
		printf(" element  popped out is:%d\n",A[*top]);
	   *top=*top-1;
	   	
	}
	
}
