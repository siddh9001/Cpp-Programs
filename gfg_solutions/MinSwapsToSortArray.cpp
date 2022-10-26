#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>& arr, int n){

    vector<pair<int, int>> temp(n);
    for(int i=0;i<n;i++){
        temp[i].first = arr[i];
        temp[i].second = i;
    }
    sort(temp.begin(), temp.end());
    int i=0, ans = 0;

    while(i < n){

        if(temp[i].second == i || temp[i].first == arr[i]){
            i++;
            continue;
        }
        else{

            swap(temp[i].first, temp[temp[i].second].first);
            swap(temp[i].second, temp[temp[i].second].second);

            if(temp[i].second != i)
                i--;
        }
        ans++;
        i++;
    }

    return ans;
}

main(){
    int n;
    cout << "Enter n : ";
    cin >> n;
    vector<int> arr(n);
    cout << "ENter array : ";
    for(int i=0;i<n;i++)cin>>arr[i];
    cout << "Minimum swaps required tom swap the array : " << minSwaps(arr, n);
}