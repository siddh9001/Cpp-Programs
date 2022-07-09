#include<iostream>
#include<vector>
using namespace std;
bool dfs(int node, vector<int> adj[], vector<bool> vis, int parent){
    vis[node] = true;
    
    for(auto nbr:adj[node]){
        if(!vis[nbr]){
            if(dfs(nbr, adj, vis, node))
                return true;
        }
        else if(parent != nbr){
            return true;
        }
    }

    return false;
}
bool isCycle(vector<int> adj[], int n){
    vector<bool> vis(n);

    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i, adj, vis, -1)) return true;
        }
    }

    return false;
}
int main(){
    int n ;
    cout << "Enter the number of vertices in graph : ";
    cin >> n;

    vector<int> adj[n];

    cout << "Enter the graph: \n";
    for(int i=0;i<n;i++){
        int m;
        cout << "Enter the number of edges from " << i << " node : ";
        cin >> m;
        for(int j=0;j<m;j++){
            int num;
            cout << "Enter the endpoint of " << j+1 << "th edge : ";
            cin >> num;
            adj[i].push_back(num);
        }
    }
    if(isCycle(adj, n))
        cout << "Graph contains a cycle.";
    else 
        cout << "Graph does not contain an cycle.";
    
}
