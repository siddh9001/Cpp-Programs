#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int a = 30;
    double b = 10000.0;
    double pi = 3.1416;
    cout.precision(3);
    cout << showpoint << a << "\t" << b << "\t" << pi <<  endl;
}