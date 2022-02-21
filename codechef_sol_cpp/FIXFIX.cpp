#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--)
	{
	    int n,k;
	    cin >> n >> k;
	    
	    if(k == n)
	    {
	        for(int i=0;i<n;i++)
	            cout << i+1 << " ";
	    }
	    
	    else if(n - k == 1)
	    {
	        cout << -1;
	    }
	    
	    else
	    {
	        int a[n];
	        for(int i=0;i<n;i++)
	            a[i] = i+1;
	            
	       //for(int i = 0, j = n-1; i < (n-k)/2; i++, j--)
	       //     swap(a[i+k], a[j]);
	        for(int i=0;i<n-k-1;i++)
	            swap(a[i+k], a[i+k+1]);
	            
	        for(int i=0;i<n;i++)
	            cout << a[i] << " ";
	    }
	    
	    cout << endl;
	}
	return 0;
}
