// Bad Character Heuristic
#include<iostream>
#include<algorithm>
using namespace std;
#define no_of_chars 256

void badCharHeuristic(string str, int size, int badchar[no_of_chars]){

    for(int i=0;i<no_of_chars;i++)
        badchar[i] = -1;

    for(int i=0;i<size;i++){
        badchar[(int)str[i]] = i;
    }
}

void search(string text, string pat){
    int n = text.length();
    int m = pat.length();

    int badchar[no_of_chars];
    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while(s < (n-m)){
        int j = m-1;

        while (j >= 0 && text[s+j] == pat[j]) j--;

        if(j < 0){
            cout << "The pat occurs at : " << s << endl;

            s += (s+m < n) ?  m - badchar[text[s+m]] : 1;
        }
        else{
            s += max(1, j - badchar[text[s+j]]);
        }
        
    }
}

main(){
    string text, pat;
    cout << "Enter the string : ";
    cin >> text;
    cout << "Enter the pattern : ";
    cin >> pat;

    search(text, pat);
}