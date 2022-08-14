// Check if reversing a sub array make the array sorted

// Difficulty Level : Medium
// Last Updated : 22 Jun, 2022
// Given an array of n distinct integers. The task is to check whether reversing any one sub-array 
// can make the array sorted or not. If the array is already sorted 
// or can be made sorted by reversing any one subarray, print “Yes“, else print “No“.
#include<iostream>
#include<algorithm>
using namespace std;

//O(nlogn) solution
// bool check(int a[], int n){
//     if(n == 1) return true;

//     int temp[n];
//     for (int i = 0; i < n; i++)
//     {
//         temp[i] = a[i];
//     }
//     sort(temp, temp+n);

//     int start=0, end=n-1;

//     while(temp[start] == a[start]) start++;
//     if(start == n) return true;

//     while(temp[end] == a[end]) end--;

//     int count = 0;
//     for (int i = start; i < end; i++)
//     {
//         if(a[i] > a[i+1]) count++;
//     }

//     if((count + 1) == (end - start + 1))
//         return true;

//     return false;
// }

//O(n) solution
bool check(int a[], int n){

    if(n == 1) return true;

    int i = 0;

    //for increasing part
    for(i=1; i < n && a[i-1] <= a[i]; i++);
    if(i == n) return true;

    //for reverse part
    int j = i;
    while(j < n && a[j] < a[j-1]){
        if(i > 1 && a[j] < a[j-2])
            return false;
        j++;
    }
    if(j == n) return true;

    int k = j;

    if(a[k] < a[i-1])
        return false;

    while(k > 1 && k < n){
        if(a[k] < a[k-1])
            return false;
        k++;
    }

    return true;      
}


main(){
    int n;
    cout << "Enter size : ";
    cin >> n;
    int a[n];
    cout << "Enter array: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "does reversing sb array makes array sorted : " << check(a, n);
    
}