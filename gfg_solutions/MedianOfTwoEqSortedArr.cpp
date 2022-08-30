// Median of Two Equal Sorted Arrays

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Time - O(n) 
//space - O(1)
int getMedian(int ar1[], int ar2[], int n){
    int i=0, j=0;
    int m1 = -1, m2 = -1;

    for (int k = 0; k <= n; k++)
    {
        if(i == n){
            m1 = m2;
            m2 = ar2[0];
            break;
        }

        else if(j == n){
            m1 = m2;
            m2 = ar1[0];
            break;
        }

        if(ar1[i] <= ar2[j]){
            m1 = m2;
            m2 = ar1[i];
            i++;
        }

        else {
            m1 = m2;
            m2 = ar2[j];
            j++;
        }
    }

    return (m1+m2)/2;
    
}


//Time - O(logn) 
//space - O(1)
int median(int arr[], int n)
{
    if (n % 2 == 0)
        return (arr[n / 2] + 
                arr[n / 2 - 1]) / 2;
    else
        return arr[n / 2];
}
int getMedian(int ar1[], int ar2[], int n){
    if (n <= 0)
        return -1;
    if(n==1)
        return (ar1[0]+ar2[0])/2;
    if(n == 2)
        return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2;

    int m1 = median(ar1, n); 
    int m2 = median(ar2, n); 

     if (m1 == m2)
        return m1;

    if (m1 < m2)
    {
        if (n % 2 == 0)
            return getMedian(ar1 + n / 2 - 1, ar2, n - n / 2 + 1);
        return getMedian(ar1 + n / 2, ar2, n - n / 2);
    }
    if(m1 > m2){
    if (n % 2 == 0)
        return getMedian(ar2 + n / 2 - 1, ar1, n - n / 2 + 1);
    return getMedian(ar2 + n / 2, ar1, n - n / 2);
    }
    

}

main(){
    int n;
    cout << "Enter n : ";
    cin >> n;
    int ar1[n], ar2[n];
    cout << "Enter first array : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> ar1[i];
    }
    cout << "\nEnter second array : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> ar2[i];
    }

    cout << "Median of two array is : " << getMedian(ar1, ar2, n);
    
}