#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--)
	{
	    string s;
	    cin >> s;
	    
	    int count = 0, n = s.length(), i = 0;
	    bool flag = true;  // for orignal configuration of doors
	    
	    if(s[0] == '0')
	    {
	        count++;
	        flag = false;
	    }
	    
	    while(i < n-1)
	    {
	        if(flag == false && s[i] == '0' && s[i+1] == '1')
	        {
	            count++;
	            flag = true;
	            i++;
	        }
	        
	        else if(flag == true && s[i] == '1' && s[i+1] == '0')
	        {
	            count++;
	            flag = false;
	            i++;
	        }
	        
	        else
	        {
	            i++;
	        }
	    }
	    
	    cout << count << endl;
	}
	return 0;
}