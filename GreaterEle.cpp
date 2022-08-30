#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> greaterEle(int a[], int n){
    vector<int> ans;
    map<int, int> mp;

    if(n == 1) {
        ans.push_back(-1);
        return ans;
    }
    if(n == 2) {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }

    map<int, int>::iterator idx, it;

    for(int i=0;i<n-2;i++){

        int cnt = 1, temp = -1;
        long val = a[i] + x;
        idx = mp.find(a[i]);

        for(it = mp.find(a[i])++; it != mp.end(); it++){

            if(cnt == 2){
                cnt = 0;
                temp = it->first;
                break;
            }

            else if(val <= it->first && idx->second < it->second && cnt < 2)
                cnt++;
        }

        if(it == mp.end() && cnt == 2) {
            temp = 
        }
    }
}

main(){
    int n, x;

    cout << "Enter n : " ;
    cin >> n;
    int a[n];
    cout << "Enter X : ";
    cin >> x;
    cout << "Enter array : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
}