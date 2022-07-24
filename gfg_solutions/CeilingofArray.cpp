#include<iostream>
using namespace std;

main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];

    int x ;
    cin >> x;

    int low = 0, high = n-1, mid;

    while(low <= high){
        mid = low + (high-low)/2;

        if(a[mid] == x)
        {
            cout << a[mid];
            return 0;
        }
        else if(x < a[mid])
            high = mid - 1;
        else    
            low = mid + 1;
    }
    cout << a[low] ;
    return  0;
}