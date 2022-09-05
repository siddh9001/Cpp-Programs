#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	getline(cin, s, ',');
	getline(cin, t);
	
	string pat="";
	for(int i=0;i<t.length();i++){
	    if(t[i] == ',' || t[i] == ' ')continue;
	    pat += t[i];
	}
	
	cout << s << "\n" << pat << "\n";
	
	bool ans = false;
	
	int n = s.length(), m = pat.length();
	int i=0, j=0;
	while(i < n && j < m){
	    if(pat[j] != '*' && s[i] != pat[j]){
	        ans = false;
	        break;
	    }
	    else if(pat[j] == '*'){
	        
	        if(j == m-1){
	            ans = true; 
	            break;
	            
	        }
	        
	        if(i < n-1 && j < m-1 && s[i+1] != pat[j+1]) 
	            i++;
	            
	        else{
	            j++;
	            i++;
	        }
	    }
	    else if(s[i] == pat[j]){
	        i++;
	        j++;
	    }
	}
	
	if(i == n && j == m) ans = true;
	cout << ans;
	
}