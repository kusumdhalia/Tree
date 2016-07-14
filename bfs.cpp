#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int v; //no of vertices
	list <int> *adj;  //pointer to n array containing adjacency list

public:
	Graph(int v)
	{
		this->v=v;
		adj=new list<int> [v];
	} //constructor
	void addEdge(int v,int w);
	void BFS(int s);
	void DFS();
	void DFSUtil(int, bool[]);
};

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}
 
// The function to do DFS traversal. It uses recursive DFSUtil()
void Graph::DFS()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print DFS traversal
    // starting from all vertices one by one
    for (int i = 0; i < v; i++)
        if (visited[i] == false)
            DFSUtil(i, visited);
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);  //adding w to v's adjacency list
}

int main()
{
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);

	g.BFS(2);
	cout<<endl;
	g.BFS(0);
	cout<<endl;
	g.DFS();
	cout<<endl;
	return (0);
}

void Graph:: BFS(int t)
{
	bool *visited =new bool[t];
	for (int i = 0; i < t; ++i)
	{
		visited[i]=false; 			//initially no nodes are visited.
	}

	list<int> q;

	visited[t]=true;
	q.push_back(t);

	list <int> :: iterator i;

	while(!q.empty())
	{
		t=q.front();
		cout<<t<<" ";
		q.pop_front();


		for(i=adj[t].begin(); i!=adj[t].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				q.push_back(*i);
			}
		}
	}


}