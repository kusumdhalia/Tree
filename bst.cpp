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
struct node* deleteNode(struct node*, int);
struct node* minValueNode(struct node*);
struct node* lca(struct node*,int,int);
void kthSmallestNode(struct node*,int);

int main()
{
	struct node* root=NULL;
	root=insert(root,34);
	insert(root,20);
	insert(root,79);
	insert(root,100);
	insert(root,1);

	inorder(root);
	cout<<endl;

	deleteNode(root,1);
	inorder(root);
	cout<<endl;

	struct node* l=lca(root,34,100);
	cout<<"LCA="<<l->d<<endl;

	kthSmallestNode(root,4);

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

/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->d)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->d)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->d = temp->d;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->d);
    }
    return root;
}


struct node* lca(struct node* h, int a,int b)
{
	if(h==NULL)
		return(NULL);
	if(h->d <a && h->d <b)
		lca(h->right,a,b);
	if(h->d >a && h->d >b)
		lca(h->left,a,b);
	return(h);
}

void kthSmallestNode(struct node *h, int k)
{
	if(h==NULL)
		return;
	static int count=1;
	kthSmallestNode(h->left,k);
	if(k==count)
		cout<<h->d;
	count++;
	kthSmallestNode(h->right,k);
}