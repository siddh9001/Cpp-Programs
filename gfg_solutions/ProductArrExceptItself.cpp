//Product of array except itself
//O(n) time without using division operator
#include<bits/stdc++.h>
using namespace std;

main(){
    int n;
    cout << "Enter n :";
    cin >> n;
    int arr[n];
    int prod[n];
    cout << "Enter array : ";

    int temp = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        prod[i] = temp;
        temp *= arr[i];
    }
    temp = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        prod[i] *= temp;
        temp *= arr[i];
    }
    cout << "The result is : ";
    for (int i = 0; i < n; i++)
    {
        cout << prod[i] << " ";
    }
    
    
    
}