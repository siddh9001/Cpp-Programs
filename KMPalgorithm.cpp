#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Time = O(n + m)
//space O(n)
vector<int> LongPrefixSuffix(string pat){
    int n = pat.length();
    vector<int> p(n, 0);
    int j;
    for(int i = 1; i < n; i++){
        j = p[i-1];

        while(j>0 && pat[i]!=pat[j])
            j = p[j-1];

        if(pat[i] == pat[j])
            j++;
        p[i] = j;
    }

    return p;
}
main(){
    string str, pat;
    cout << "Enter the string : ";
    cin >> str;
    cout << "Enter the pattern : ";
    cin >> pat;

    vector<int> lps = LongPrefixSuffix(pat);

    int pos = -1;
    int i(0), j(0);

    while(i < str.size()){
        if(str[i] == pat[j]){
            i++, j++;
        }
        else{
            if(j!=0)
                j = lps[j-1];
            else    
                i++;
        }
        if(j == pat.size()){
            pos = i - pat.size() + 1;
            break;
        }
    }

    cout << "Substr found at : " << pos;
}