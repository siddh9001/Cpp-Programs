#include <iostream>
#include <climits>
using namespace std;


int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--)
	{
	    int n, even = 0;
	    cin >> n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin >> a[i];
	        if(a[i]%2 == 0)
	            even++;
	    }
	        
	   if(n == even)
	   {
	       int ans = INT_MAX, c;
    	   for(int i=0;i<n;i++)
    	   {
    	        c = 0;
    	        while(a[i]%2 != 1)
    	        {
    	            a[i] /= 2;
    	            c++;
    	        }
    	        
    	        if(c < ans)
    	            ans = c;
    	      
    	   }
    	   
    	   cout << ans;
	   }
	   else
	    cout << 0;
	    
	   cout << endl;
	}
	return 0;
}
