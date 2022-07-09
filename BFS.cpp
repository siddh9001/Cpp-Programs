#include<iostream>
#include<queue>
#include<vector>

using namespace std;

// void BFS(int G[][8], int n, int root)
// {
//     vector<int> res;
//     vector<int> visited(n,0);
//     queue<int> q;

//     res.push_back(root);
//     visited[root] = 1;
//     q.push(root);

//     while(!q.empty())
//     {
//         int temp = q.front();
//         q.pop();

//         for(int i = 1; i < 8; i++)
//         {
//             if(G[temp][i] == 1 && !visited[i])
//             {
//                 visited[i] = 1;
//                 res.push_back(i);
//                 q.push(i);
//             }
//         }
//     }
    
//     cout << "BFS: ";
//     for(auto i:res)
//         cout << i << " " ;
// }

// int main()
// {
//    int G[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
//                    {0, 0, 1, 1, 1, 0, 0, 0},
//                    {0, 1, 0, 1, 0, 0, 0, 0},
//                    {0, 1, 1, 0, 1, 0, 0, 0},
//                    {0, 1, 0, 1, 1, 1, 0, 0},
//                    {0, 0, 0, 1, 1, 0, 1, 1},
//                    {0, 0, 0, 0, 0, 1, 0, 0},
//                    {0, 0, 0, 0, 0, 1, 0, 0}};

//    BFS(G,8,6);
//     return 0;
// }

void BFS(int start, int v, vector<int> adj[], vector<bool> visited){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr] = true;
            }
        }
    }
}

int main(){
    int v,e;
    cout << "Enter the number of vertices : ";
    cin >> v;
    cout << "Enter the number of edges : ";
    cin >> e;

    vector<int> adj[v];
    vector<bool> visited(v, false);

    for(int i=0;i<e;i++){
        int u,v;
        cout << "Enter the u :";
        cin >> u;
        cout << "Enter the v : ";
        cin >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    BFS(0, v, adj, visited);
}