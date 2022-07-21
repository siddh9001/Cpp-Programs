// Create a matrix with alternating rectangles of O and X

// Write a code which inputs two numbers m and n and creates a matrix of size n x m (n rows and m columns) in which every elements is either X or 0. The Xs and 0s must be filled alternatively, the matrix should have outermost rectangle of Xs, then a rectangle of 0s, then a rectangle of Xs, and so on.

// Input: n = 3, m = 3
// Output: Following matrix 
// X X X
// X 0 X
// X X X

// Input: n = 4, m = 5
// Output: Following matrix
// X X X X X
// X 0 0 0 X
// X 0 0 0 X
// X X X X X

// Input:  n = 5, m = 5
// Output: Following matrix
// X X X X X
// X 0 0 0 X
// X 0 X 0 X
// X 0 0 0 X
// X X X X X

// Input:  n = 6, m = 7
// Output: Following matrix
// X X X X X X X
// X 0 0 0 0 0 X
// X 0 X X X 0 X
// X 0 X X X 0 X
// X 0 0 0 0 0 X
// X X X X X X X 

#include<iostream>
#include<vector>
using namespace std;
void printpat(int n, int m){

    vector<vector<char>> mat(n, vector<char>(m));

    int t1 = n, t2 = m;
    int f = 0;
    int mts = 0, mbs = n-1, nts = m-1, nbs = 0;
    bool flag = false;

    while(t1 > 0  && t2 > 0){
            
            if(f==0)flag = !flag;
            
            if(f == 0){
                
                // traverse row left to right
                
                for(int i=mts;i<=nts;i++){
                    if(flag){ mat[mts][i] = 'X';}
                    else mat[mts][i] = '0';
                }
                mts++;
                t1--;
                f = 1;
                
            }
            
            else if(f == 1){
                
                //traverse col top to bottom
                
                for(int i=mts;i<=mbs;i++){
                    if(flag){ mat[i][nts] = 'X';}
                    else mat[i][nts] = '0';
                }
                nts--;
                t2--;
                f=2;
            }
            
            else if(f == 2){
                //traverse row right to left
                
                for(int i=nts;i>=nbs;i--){
                    if(flag){ mat[mbs][i] = 'X';}
                    else mat[mbs][i] = '0';
                }
                mbs--;
                t1--;
                f=3;
            }
            
            else if(f == 3){
                
                //traverse col bottom to top
                
                for(int i=mbs;i>=mts;i--){
                    if(flag){ mat[i][nbs] = 'X';}
                    else mat[i][nbs] = '0';
                }
                nbs++;
                t2--;
                f=0;
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << mat[i][j] << "  ";
            }
            cout << "\n";
        }
}
main(){
    int n, m;
    cout << "Enter rows : ";
    cin >> n;
    cout << "Enter cols : ";
    cin >> m;

    printpat(n,m);
}