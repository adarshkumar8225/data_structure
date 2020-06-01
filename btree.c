#include<stdio.h>
#include<stdlib.h>




struct bs_node
{
	struct bs_node *left;
	int data;
	struct bs_node *right;
};

void inorder_trav(struct bs_node *root);
void preorder_trav(struct bs_node *root);
void postorder_trav(struct bs_node *root);


void insert_bt(struct bs_node **root,int p);


int main()
{
	int i,p=0,N;
	struct bs_node *root=NULL;
	printf("Enter no. of node in Tree:");
	scanf("%d",&N);
	printf("\nEnter the numbers:");
	for(i=0;i<N;i++)
	{
		
		scanf("%d",&p);
                insert_bt(&root,p);
	}
	printf("\n");
        printf("Inorder sequence:");

        inorder_trav(root);

        printf("\n");
        printf("Preorder sequence:");

        preorder_trav(root);

        printf("\n");
        printf("Postorder sequence:");

        postorder_trav(root);

        printf("\n");
        return 0;

}

//function to insert into binary tree.Arugment is double pointer as we are changing the tree each time we insert a node.
void insert_bt(struct bs_node **root,int p)
{
	struct bs_node *trav,*temp;

	trav=*root;
	temp=(struct bs_node *)malloc(sizeof(struct bs_node ));
	temp->left=NULL;
	temp->right=NULL;
	temp->data=p;
	
	if(trav==NULL) *root=temp;//here *root means the value pointed by root variable will contain the temp.
	else
	{
		if(trav->data >p) insert_bt(&(trav->left),p);//recursion to fill left subtree.
		else insert_bt(&(trav->right),p);//recursion to fill right subtree.

	}


}

//function for inorder traversal.
void inorder_trav(struct bs_node *root)
{
	struct bs_node *trav;
	trav=root;
	if(trav== NULL) return ;
	inorder_trav(trav->left);//function for left subtree.
	printf("%d	",trav->data);//print data
	inorder_trav(trav->right);// function for right subtree.
}

//function for preorder traversal
void preorder_trav(struct bs_node *root)
{
        struct bs_node *trav;
        trav=root;
        if(trav==NULL) return ;
        printf("%d      ",trav->data);
        preorder_trav(trav->left);
        preorder_trav(trav->right);
}

//function for post order traversal.
void postorder_trav(struct bs_node *root)

{
        struct bs_node *trav;
        trav= root;
        if(trav == NULL) return;
        postorder_trav(trav->left);
        postorder_trav(trav->right);
        printf("%d      ",trav->data);

}

