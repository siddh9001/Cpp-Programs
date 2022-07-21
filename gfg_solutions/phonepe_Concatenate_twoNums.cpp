#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
long long concatenate_nums(int n, int X, vector<int> numbers)
{
    long long ans = 0;
    unordered_map<string , int> mp;
    string x = to_string(X);
    for(auto i:numbers)
        mp[to_string(i)]++;
    
    for(int i=0;i<x.length();i++)
    {
        string p = x.substr(0,i+1);
        string q = x.substr(i+1);
        
        if(p == q)
        {
            ans += (mp[p]*(mp[q]-1));
        }
        else
            ans += mp[p]*mp[q];
    }
    
    return ans;
}
int main()
{
    int n, x;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    cin >> x;
    cout << concatenate_nums(n, x, a);
}