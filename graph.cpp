#include <bits/stdc++.h>
using namespace std;

struct Graph
{
	int v;
	struct AdjList *arr;		//array of adjacency list
};

struct AdjList
{
	struct AdjListNode *head;
};

struct AdjListNode
{
	int dest;						//second node of edge
	struct AdjListNode *next;		//not null if there is another edge
};


struct AdjListNode *newAdjListNode(int );
struct Graph* createGraph(int);
void addEdge(struct Graph*,int,int);

struct AdjListNode *newAdjListNode(int t)
{
	struct AdjListNode *node= (struct AdjListNode*) malloc (sizeof(struct AdjListNode));
	node->dest=t;
	node->next= NULL;
	return(node);
}

struct Graph* createGraph(int n)
{
	struct Graph* g= (struct Graph*) malloc (sizeof(struct Graph*));
	g->v=n;

	g->arr= (struct AdjList*) malloc (sizeof(struct AdjList*));

	for(int i=0;i<n;i++)
		g->arr[i].head=NULL;
	return(g);
}

void addEdge(struct Graph* g, int s, int d)
{
	struct AdjListNode *node= newAdjListNode(d); //edge from source to destination
	node->next = g->arr[s].head;
	g->arr[s].head=node;

	node=newAdjListNode(s); //edge from destination to source
	node->next = g->arr[d].head;
	g->arr[d].head=node;
}

void printGraph(struct Graph* g )
{
	int t;
	for(t=0; t<g->v; t++)
	{
		struct AdjListNode *p= g->arr[t].head;
		cout<<"\n Adjacency List of vertex"<<t<<endl;
		while(p)
		{
			cout<<p->dest;
			p=p->next;
		}
		cout<<endl;
	}
}

int main()
{
	int n=5;
	struct Graph *g = createGraph(n);
	addEdge(g,0,1);
	addEdge(g,0,3);
	addEdge(g,0,4);
	addEdge(g,1,2);
	addEdge(g,2,3);
	addEdge(g,3,4);
	return(0);
}