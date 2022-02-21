#include<iostream>
using namespace std;

int main()
{
    long long int n;
    cout << "Enter a number: ";
    cin >> n;

    long long int n1 = 0, n2 = 1, sum = 0, count = 2;

    while(sum < n)
    {
        sum = n1 + n2;
        n1 = n2;
        n2 = sum;
        count++;
    }

    if(sum == n)
        cout << "The entered number is " << count << "th fibonacci number.";
    else
        cout << "Entered Number is not a fibonacci number.";

    return 0;
}