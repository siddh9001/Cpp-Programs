#include<iostream>
#include<queue>

using namespace std;

void BFS(int G[][8], int n, int root)
{
    vector<int> res;
    vector<int> visited(n,0);
    queue<int> q;

    res.push_back(root);
    visited[root] = 1;
    q.push(root);

    while(!q.empty())
    {
        int temp = q.front();
        q.pop();

        for(int i = 1; i < 8; i++)
        {
            if(G[temp][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                res.push_back(i);
                q.push(i);
            }
        }
    }
    
    cout << "BFS: ";
    for(auto i:res)
        cout << i << " " ;
}

int main()
{
   int G[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 0, 0, 0},
                   {0, 1, 0, 1, 1, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};

   BFS(G,8,6);
    return 0;
}