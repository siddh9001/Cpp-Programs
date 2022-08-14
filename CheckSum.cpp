//Given an array and a number return subarray which contain the sum of different lengths
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> twoSum(vector<int> a, int start, int n, int target){

    vector<vector<int>> res;

    int low = start;
    int high = n-1;
    int sum = 0;
    sort(a.begin(), a.end());

    while(low < high){
        if(low > start and a[low-1] == a[low]) {low++; continue;}

        sum = a[low] + a[high];

        if(sum > target)
            high--;
        else if(sum == target){
            vector<int> t;
            t.push_back(a[low]);
            t.push_back(a[high]);
            res.push_back(t);
            low++;
            high--;
        }
        else low++;
    }

    return res;
}

vector<vector<int>> threeSum(vector<int> a, int n, int target){
    vector<vector<int>> res;
    int sum;

    sort(a.begin(), a.end());

    for(int i=0;i<n-2;i++){
        if(i > 0 && a[i-1] == a[i]) continue;
        int low = i+1, high = n-1;
        while(low < high){
            sum = a[i] + a[low] + a[high];
            if(sum > target)
                high--;
            else if(sum == target){
                vector<int> t;
                t.push_back(a[i]);
                t.push_back(a[low]);
                t.push_back(a[high]);
                res.push_back(t);
                low++;
                // high--;
            }
            else low++;
        }
    }
    return res;
}

vector<vector<int>> fourSum(vector<int> a, int n, int x){
    set<vector<int>> ans;
    int sum;
    sort(a.begin(), a.end());

    for(int i=0;i<n-3;i++){
        if(i > 0 and a[i-1] == a[i]) continue; // to skip the same elements
        for(int j=i+1;j<n-2;j++){
            if(j > 0 and a[j-1] == a[j]) continue;
            int left = j+1;
            int right = n-1;

            while(left < right){
                sum = a[i]+a[j]+a[left]+a[right];

                if(sum > x)
                    right--;
                else if(sum == x){
                    vector<int> t;
                    t.push_back(a[i]);
                    t.push_back(a[j]);
                    t.push_back(a[left]);
                    t.push_back(a[right]);
                    ans.insert(t);
                    left++;
                    // right--;
                }
                else
                    left++;
            }
        }

    }
    vector<vector<int>> res;
    for(auto i:ans)
        res.push_back(i);

    return res;
}
main(){
    int n;
    cout << "Enter n : ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter Array : \n";
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int x;
    cout << "Enter X : ";
    cin >> x;

    vector<vector<int>> sum2 = twoSum(a, 0, n, x);
    cout << "\n The two sum is : ";
    if(sum2.size() == 0) cout << "-1";
    else{
        for(auto i:sum2)
            cout << "(" << i[0] << ", " << i[1] << ")\n";
    }


    vector<vector<int>> sum3 = threeSum(a, n, x);
    cout << "\n three sum is : ";
    if(sum3.size() == 0) cout << "-1";
    else{
    for(auto i:sum3)
        cout << "(" << i[0] << ", " << i[1] << ", " << i[2] <<  ")\n";
    }

    vector<vector<int>> sum4 = fourSum(a, n, x);
    cout << "\n Four sum is : ";
    if(sum4.size() == 0) cout << "-1";
    else{
    for(auto i:sum4)
        cout << "(" << i[0] << ", " << i[1] << ", " << i[2] << ", " << i[3] << ")\n";
    }
    
}