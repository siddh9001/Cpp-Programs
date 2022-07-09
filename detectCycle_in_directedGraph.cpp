#include<iostream>
#include<vector>
using namespace std;
bool dfs(int node, vector<int> adj[], vector<bool> vis, vector<bool> recS){
    vis[node] = true;
    recS[node] = true;
    
    for(auto nbr:adj[node]){
        if(!vis[nbr])
            if(dfs(nbr, adj, vis, recS)) return true;
            // if a node is visited and present in current recursion stack then only we detect a cycle
        else if(recS[nbr])   
            return true;
    }
    recS[node] = false;
    return false;
}
bool isCycle(vector<int> adj[], int n){
    vector<bool> vis(n);
    vector<bool> recS(n); // to maintain the recursion stack

    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i, adj, vis, recS)) return true;
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