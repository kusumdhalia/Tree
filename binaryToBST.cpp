#include <bits/stdc++.h>
using namespace std;

struct node* insert(int);
void inorder(struct node*);
int countNode(struct node*);
void binarytobst(struct node*);
void storeInorder(struct node*, int*,int*);
int compare(const void*, const void* );
void arrtoBst(struct node*,int* ,int*);

struct node
{
	int d;
	node *left, *right;
};

int main()
{
	struct node* root= insert(40);
	root->left=insert(50);
	root->right=insert(60);
	root->left->left=insert(33);
	root->left->right=insert(44);
	root->right->left=insert(89);
	root->right->right=insert(70);

	inorder(root);
	cout<<endl;

	binarytobst(root);
	inorder(root);
	cout<<endl;

	return(0);
}

struct node* insert(int n)
{
	struct node* t= (struct node*) malloc(sizeof(struct node*));
	t->d=n;
	t->right=NULL;
	t->left=NULL;
	return(t);
}
void inorder(struct node *h)
{
	if(h==NULL)
		return;
	inorder(h->left);
	cout<<h->d<<" ";
	inorder(h->right);
}

int countNode(struct node* h)
{
	if(h==NULL)
		return(0);
	return( countNode(h->left)+ countNode(h->right) +1);
}

void binarytobst(struct node *h)
{
	if(h==NULL)
		return;
	int n=countNode(h);
	int *a= new int[n];
	int i=0;

	storeInorder(h,a,&i);
	qsort (a, n,sizeof(a[0]),compare);


	i=0;
	arrtoBst(h,a,&i);
}

void storeInorder(struct node* h, int *a, int *b)
{
	if(h==NULL)
		return;

	storeInorder(h->left,a,b);
	a[*b]=h->d;
	(*b)++;
	storeInorder(h->right,a,b);
}

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

void arrtoBst(struct node *h, int *a, int *b)
{
	if(h==NULL)
		return;

	arrtoBst(h->left,a,b);
	h->d=a[*b];
	(*b)++;
	arrtoBst(h->right,a,b);
}