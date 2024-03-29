#include <iostream>
using namespace std;
 
#define N 4

void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
                cout << sol[i][j] <<  " ";
        cout << endl;
    }
}
 

bool isSafe(int maze[N][N], int x, int y)
{
    
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y]  > 0)
        return true;
 
    return false;
}
 
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    
    if (x == 0 && y == N - 1 && maze[x][y] > 0) 
    {
        sol[x][y] = maze[x][y];
        return true;
    }
 
    
    if (isSafe(maze, x, y) == true) 
    {
          if (sol[x][y] > 0)
              return false;
       
        sol[x][y] = maze[x][y];
 
        
        if (solveMazeUtil(maze, x + 1, y, sol) == true)
            return true;
 
        
        if (solveMazeUtil(maze, x , y + 1, sol) == true)
            return true;
       
       
        if (solveMazeUtil(maze, x - 1, y, sol) == true)
            return true;
 
       
        
        if (solveMazeUtil(maze, x, y - 1, sol) == true)
            return true;
 
       
        sol[x][y] = 0;
        return false;
    }
 
    return false;
}


bool solveMaze(int maze[N][N])
{
    int sol[N][N] = { { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 } };
 
    if (solveMazeUtil(maze, N-1, 0, sol) == false) 
    {
        cout << "Solution doesn't exist";
        return false;
    }
 
    printSolution(sol);
    return true;
}
 

int main()
{
    /*int maze[N][N] = { { 1, 0, 0, 0 },    //test case 1
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };*/
                    
                    
    int maze[N][N] = { { 2, 2, 2, 1 },    //test case 2
                       { 2, 0, 0, 1 },
                       { 1, 0, 0, 1 },
                       { 1, 3, 1, 1 } };
 
    solveMaze(maze);
    
    return 0;
}