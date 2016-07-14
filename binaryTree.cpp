#include <bits/stdc++.h>
using namespace std;


struct node* insertNode(int);
void inorder(struct node*);
void preorder(struct node *);
void postorder(struct node *);
void printLevelOrder(struct node*);
int height(struct node*);
void printGivenLevel(struct node *,int);
int getWidth(struct node*,int);
int getMaxWidth(struct node*);

struct node
{
	int d;
	struct node *left;
	struct node *right;
};



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

	cout<<"inorder traversal"<<endl;
	inorder(root);
	cout<<endl<<"preorder traversal"<<endl;
	preorder(root);
	cout<<endl<<"postorder traversal"<<endl;
	postorder(root);

	cout<<endl<<"level order traversal"<<endl;
	printLevelOrder(root);
	cout<<endl;

	return(0);
}

void inorder(struct node *t)
{
	if(t==NULL)
		return;
	inorder(t->left);
	cout<< t->d<<"\t";
	inorder(t->right);
}

void preorder(struct node *t)
{
	if(t==NULL)
		return;
	cout<<t->d<<"\t";
	preorder(t->left);
	preorder(t->right);
}

void postorder(struct node *t)
{
	if(t==NULL)
		return;
	postorder(t->left);
	postorder(t->right);
	cout<<t->d<<"\t";
}

struct node* insertNode(int n)
{
	struct node* h= (struct node*) malloc(sizeof(struct node *));
	h->d=n;
	h->left=NULL;
	h->right=NULL;
	return(h);
}

void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}
 
/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->d);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
 

int getMaxWidth(struct node * r)
{
	int maxw=0;
	for(int i=1;i<= height(r);i++)
	{
		int w=getWidth(r,i);
		if(w>maxw)
			maxw=w;
	}
	return(maxw);
}

int getWidth(struct node* h,int t)
{
	if(h==NULL)
		return(0);
	if(t==1)
		return(1);
	else if(t>1)
	{
		return( getWidth(h->left,t-1)+ getWidth(h->right,t-1));
	}
}