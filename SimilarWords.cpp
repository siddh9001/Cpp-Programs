// Given an array of words return the number of pairs that are similar
// two strings are said to be similar if they have same distinct alphabets
// ex: "abcbca" is similar to "abc" but "abc" not similar to "abcd"
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int toint(vector<int> arr){
    int ans = 0;
    for(int i=arr.size()-1, k=0; i>=0; i--, k++){
        ans += arr[i]*pow(2, k);
    }

    return ans;
}

long CountSimilarStrings(vector<string> arr){
    vector<int> alph(26, 0);
    map<int, int> mp;

    for (auto str : arr)
    {
        for(auto l : str)
            alph[l - 'a'] = 1;

        int k = toint(alph);
        mp[k]++;

        for(int i=0;i<26;i++)
            alph[i] = 0;
    }
    long ans = 0;
    for(auto it : mp){
        int x = it.second;
        ans += (x*(x-1))/2;
    }

    return ans;
}

main(){
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    vector<string> arr(n);
    cout << "Enter the array : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "pair of similar strings : " << CountSimilarStrings(arr);
    
}