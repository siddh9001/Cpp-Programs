#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> adj[1005];
    int n,m;
    cout << "enter n & m: ";
    cin >> n >> m;
    cout << "enter adjancency list: \n";
    for(int i=0;i<m;i++)
    {
        int u,v;
        cout << "Enter u & v: ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cout << endl;
    }
    cout << endl;
    for(int i=1;i<=n;i++){
        cout << i << " : ";
        for(auto &i:adj[i]) 
            cout << i << " ";
        cout << endl;
    }
}