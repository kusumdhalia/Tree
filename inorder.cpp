#include <bits/stdc++.h>
using namespace std;

struct node 
{
	int d;
	struct node *left;
	struct node *right;
};

void inorder(struct node *);
struct node* insertNode(int);

int main()
{
	struct node *root;

	root=insertNode(1);
	root->left=insertNode(2);
	root->right=insertNode(3);
	root->left->left=insertNode(4);
	root->left->right=insertNode(5);
	root->right->left=insertNode(6);
	root->right->right=insertNode(7);

	inorder(root);

	return(0);
}

struct node* insertNode(int n)
{
	struct node *h=(struct node*)malloc (sizeof(struct node*));
	h->d=n;
	h->left=NULL;
	h->right=NULL;
}

void inorder(struct node *h)
{
	struct node* current=h;

	while(current)
	{
		if(!current->left)
		{
			cout<<current->d<<"\t";
			current=current->right;
		}
		else
		{
			/* Find the inorder predecessor of current */
	      	struct node* pre = current->left;
	      	while(pre->right != NULL && pre->right != current)
	        pre = pre->right;
	 
	       /* Make current as right child of its inorder predecessor */
	      	if(pre->right == NULL)
	      	{
	        	pre->right = current;
	        	current = current->left;
	      	}
	             
	       /* Revert the changes made in if part to restore the original 
	        tree i.e., fix the right child of predecssor */   
	      	else 
	      	{
		        pre->right = NULL;
		        printf(" %d ",current->d);
		        current = current->right; 	
			}
		}
	}
}