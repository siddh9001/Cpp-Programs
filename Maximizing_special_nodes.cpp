#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> adj[1005],radj[1005];
int fun(vector<int> g[],int n)
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(auto j:g[i])
        {
            if(g[j].size()==0){ans++;break;}
        }
    }
    return ans;
}
int main() {
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    cout<<max(fun(adj,n),fun(radj,n));
    return 0;
}