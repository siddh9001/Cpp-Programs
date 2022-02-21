#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsOfGraph(int v, vector<int> adj[])
{
	vector<int> bfs;
	vector<int> vis(v+1,0);
	
	for(int i=1;i<=v;i++)
	{
		if(!vis[i])
		{
			queue<int> q;
			q.push(i);
			vis[i]=1;
			while(!q.empty())
			{
				int node=q.front();
				cout<<node<<" ";
				q.pop();
				bfs.push_back(node);
				
				for(auto it : adj[node])
				{
					if(!vis[it])
					{
						q.push(it);
						vis[it]=1;
					}
				}
			}
		}
	}
	return bfs;
}

int main()
{
	int i,n,e;
	cin>>n>>e;
	vector<int> adj[n+1];
	for(i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> ans=bfsOfGraph(n,adj);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}