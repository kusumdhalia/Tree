#include <bits/stdc++.h>
using namespace std;

struct node
{
	int d;
	struct node* left;
	struct node* right;
};


struct node* newNode(int);
struct node* insert(struct node*,int);
void inorder(struct node*);
//struct node* deleteNode(struct node*, int);
struct node* minValueNode(struct node*);
//struct node* lca(struct node*,int,int);
void findPreSuc(struct node*,struct node*,struct node*,int);


int main()
{
	struct node* root=NULL;
	root=insert(root,34);
	insert(root,20);
	insert(root,79);
	insert(root,100);
	insert(root,1);
	insert(root,50);

	inorder(root);
	cout<<endl;

	struct node *p,*s;
	p=s=NULL;
	findPreSuc(root,p,s,50);
	cout<<"Predecessor="<<p->d<<endl;
	cout<<"Successor="<<s->d<<endl;

	return(0);
}

struct node* newNode(int p)
{
	struct node* h= (struct node *) malloc(sizeof(struct node *));
	h->d=p;
	h->left=NULL;
	h->right=NULL;
}

struct node* insert(struct node* p,int n)
{
	if(p==NULL)
		{  
			return(newNode(n));
		}

	else
	{
		//struct node* t=p;
		if(n < (p->d))
		{
			p->left=insert(p->left,n);
		}
		else
		{
			p->right=insert(p->right,n);
		}
	}	

}

struct node* minValueNode(struct node * t)
{
	struct node *c=t;

	while( c->left!=NULL)
		c=c->left;

	return (c);
}
void inorder(struct node* p)
{
	if(p==NULL)
		return;
	inorder(p->left);
	cout << p->d<<"\t";
	inorder(p->right);
}

void findPreSuc(struct node* h, struct node *p, struct node *s,int k)
{
	if(h==NULL)
		return;

	if(h->d == k)
	{
		if(h->left!=NULL)      		//predecessor is rightmost node in left subtree
		{
			struct node* t= h->left;

			while(t->right)
				t=t->right;
			p=t;
		}

		if(h->right!=NULL)
		{
			struct node *t=h->right;

			while(t->left)
				t=t->left;
			s=t;
		}
	}

	if(k> h->d)
	{
		p=h;
		findPreSuc(h->right,p,s,k);
	}
	if(k< h->d)
	{
		s=h;
		findPreSuc(h->left,p,s,k);
	}
}