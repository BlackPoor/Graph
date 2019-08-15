#include<iostream>
#include<list>
#include<stack>
#include<deque>
#include<queue>
#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>

using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void DFSUtil(int v,bool visited[]);
	public:
	Graph(int V);
	void addEdge(int v,int w);
	void DFS(int v);
};

Graph::Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
}

void addEdge(int v,int w)
{
	adj[v].push_back(w);
}

void DFSUtil(int v,int visited[])
{
	visited[v]=true;
	std::cout<<v<<" ";
	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();++i)
	{
		if(!visited[*i])
		{
			DFSUtil(*i,visited);
		}
	}
	return;
}

void DFS()
{
	bool *visited=new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false)
		{
			DFSUtil(i,visited);
		}
	}
}

int main()
{ 
	int test;
	std::cin>>test;
	while(test--)
	{
		int v;
		std::cin>>v;
		Graph g(v);
		int n,m,k;
		std::cin>>n;
		for(int i=0;i<n;i++)
		{
			std::cin>>m>>k;
			g.addEdge(m,k);
		}
		std::cout<<"DFS is given below"<<endl;
		g.DFS();
	}
	return 0;
}
/*
void dfs(int s, vector<int> g[], bool vis[])
{
    vis[s]=true;
    cout<<s<<" ";
    vector<int>::iterator i;
    for(i=g[s].begin();i!=g[s].end();++i){
        if(!vis[*i])
            dfs(*i,g,vis);
    }
    
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0,g,vis);
        
        cout<<endl;

    }
}*/
