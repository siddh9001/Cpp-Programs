// idea is to traverse the array and use the absolute value of each element as an index and covert 
// the value at that index as negative to mark it as visited.
#include<iostream>
using namespace std;

main(){
    int n;
    cout << "Enter the number of elements in array : ";
    cin >> n;

    int a[n];
    cout << "Enter the values of array : \n";
    for(int i=0;i<n;i++)
        cin >> a[i];

    cout << "The repeating element is : ";
    for(int i=0;i<n;i++){
        if(a[abs(a[i]) - 1] > 0)
            a[abs(a[i]) - 1] = -a[abs(a[i]) - 1];
        else
        {    cout << abs(a[i]) << "\n"; break;}
    }

    cout << "\nThe missing number is : ";
    for(int i=0;i<n;i++){
        if(a[i] > 0)
            cout << i+1 << "\n";
    }
}