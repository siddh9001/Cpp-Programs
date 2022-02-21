#include <bits/stdc++.h>

using namespace std;

#define MAX 200001
int minOperations(vector<int> arr, int threshold, int d) {
    vector<int> freq[MAX];
    int n = arr.size();
    for(int i=0; i<n;i++)
    {
        int count = 0;
        freq[arr[i]].push_back(0);
        
        while(arr[i] > 0){
            count++;
            arr[i] /= d;
            freq[arr[i]].push_back(count);
        }
    }
    
    int res = INT_MAX;
    for(int i=0;i<MAX;i++)
    {
        int moves;
        if(freq[i].size() >= threshold){
            
            moves = 0;
            sort(freq[i].begin(), freq[i].end());
            
            for(int j=0;j<threshold;j++)
                moves += freq[i][j];
        }
        
        res = min(res, moves);
    }
    
    return res;
}
int main()
{
    int n,th,d;
    cin >> n;
    vector<int> a;
    for(int i=0;i<n;i++)
        cin >> a[i];

    cin >> th >> d;

    cout << "Solution: " << minOperations(a, th, d);
}