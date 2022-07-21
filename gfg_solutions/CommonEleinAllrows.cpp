// Find a common element in all rows of a given row-wise sorted matrix
// Given a matrix where every row is sorted in increasing order. Write a function that finds and returns a common element in all rows. If there is no common element, then returns -1.

#include<iostream>
#include<vector>
#include<map>
using namespace std;


//Brute Force
//this binary search will consider all types of test cases
// bool search(vector<vector<int>> mat, int row, int ele){
//     int start = 0;
//     int end = mat[0].size()-1;

//     while(start < end){
//         int mid = start + (end-start)/2;  
//         // if we do (start+end)/2 then for large integers the value of sum will be greater than 
//         // int max value and sum will be negative and after division the value will still be -ve;

//         if(mat[row][mid] == ele){
//             cout << "\n\t" << mat[row][mid] << "\n";
//             return true;
//         }
        
//         else if(mat[row][mid] < ele)
//             start = mid + 1;
//         else
//             end = mid;
//     }
//     if(mat[row][start] == ele)return true;
//     if(mat[row][end] == ele)return true;

//     return false;
// }

// int commEle(vector<vector<int>> mat, int n, int m){

//     for(int i=0;i<m;i++){
//         int ele = mat[0][i];
//         int count = 1;
//         for(int j=1;j<n;j++){
//             if(search(mat, j, ele)){
//                 count++;
//             }
//         }
//         if(count == n)
//             return ele;
//     }
//     return -1;
// }

//Efficient solution O(n*m) space(O(m))
vector<int> commEle(vector<vector<int>> mat, int n, int m){
    vector<int> ans;
    map<int, int> mp;

    for(int i=0;i<m;i++)
        mp[mat[0][i]] = 1; // here one is the row number will be helpful in removing the duplicacy

    for(int i = 1; i < n; i++){
        for(int j=0;j<m;j++){
            if(mp[mat[i][j]] && i == mp[mat[i][j]])
                mp[mat[i][j]]++;

            if(i == n-1 && mp[mat[i][j]] && mp[mat[i][j]] == n){
                ans.push_back(mat[i][j]);
            }

        }
    }

    return ans;
}

int main(){
    int n;
    int m;
    cout << "Enter no. of rows : ";
    cin >> n;
    cout << "Enter no. of cols : ";
    cin >> m;
    vector<vector<int>> a(n, vector<int>(m));
    cout << "Enter matrix : (press enter after every number) : ";

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << a[i][j] << "  ";
        }
        cout << "\n";
    }

    cout << "Common Element in all the rows is : " ;
    vector<int> ans = commEle(a, n, m);
    for(int i=0;i<ans.size();i++)
        cout << ans[i] <<  " ";
}