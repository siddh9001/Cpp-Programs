#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dfs(int node, int parent, vector<int> adj[], vector<bool>& vis, vector<int>& par, vector<int>& recS){
    vis[node] = true;
    par[node] = parent;
    recS.push_back(node);

    for(auto nbr:adj[node]){
        if(!vis[nbr]){
            int z = dfs(nbr, node, adj, vis, par, recS);
            if(z!=-1)
                return z;
        }
        else if(vis[nbr] == 1){
            int sum = nbr;
            while(node != nbr){
                sum += node;
                node = par[node];
            }
            if(node == nbr)
                return sum;
            return -1;
        }
    }
    return -1;
}

int largestSumCycle(vector<int> g, int n){
    int ans = -1;
    vector<bool> vis(n);
    vector<int> par(n);
    vector<int> adj[n];
    vector<int> recS(n);

    //creating an adjacent matrix
    for(int i=0;i<n;i++){
        if(g[i] != -1)
            adj[i].push_back(g[i]);
    }

    for(int i=0;i<n;i++){
        if(!vis[i]){
            ans = max(ans, dfs(i, -1, adj, vis, par, recS));
            for(auto i:temp)
                vis[i] = 2;
        }
        temp.clear();
    }

    return ans;
}
int main(){
    int n ;
    cout << "Enter the number of edges: ";
    cin >> n;
    vector<int> g(n);
    cout << "Enter the array : \n";
    for(int i=0;i<n;i++)
        cin >> g[i];
    cout << largestSumCycle(g,n);
}