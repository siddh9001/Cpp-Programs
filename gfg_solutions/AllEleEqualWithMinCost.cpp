// Make all array elements equal with minimum cost

// Given an array which contains integer values, we need to make all values of 
// this array equal to some integer value with minimum cost where the cost of 
// changing an array value x to y is abs(x-y). 

#include<iostream>
#include<algorithm>
using namespace std;

main(){
    int n;
    cout << "Enter n : ";
    cin >> n;
    int a[n];
    cout << "Enter array : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    int mid = n/2;

    int cost = 0;
    for(int i=0;i<n;i++){
        cost += abs(a[i] - a[mid]);
    }

    cout << "Min Cost : " << cost;
}
