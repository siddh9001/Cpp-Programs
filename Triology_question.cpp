/* Find the minimum number of swaps such that no two pigeons should face to each other 
    R -> pigeon face to right direction 
    L -> pigeon face to left direction

    Ex : RRLLL
    ouput: 2
    Explaination:  we can change the first 2 R's to L's;

    Can be implemented using stack
*/
#include <iostream>
#include <stack>
using namespace std;

int main(){
    string s;
    cout << "Enter the string: ";
    cin >> s;

    stack<char> st;
    int count = 0;

    for(int i=0;i<s.length();i++){
        if(s[i] == 'R')
            st.push(s[i]);

        if(!st.empty() and s[i] == 'L' and st.top() == 'R'){
            st.pop();
            count++;
        }
    }

    cout << "minimum number of swaps required are : " << count;
}