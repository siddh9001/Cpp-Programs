#include<iostream>
#include<stack>
using namespace std;

bool ismatch(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}

string cb(string s)
{
    stack<char> st;
    for(int k=0;k<s.length();k++)
    {
        if(s[k] == '(' || s[k] == '{' || s[k] == '[')
            st.push(s[k]);
        else if(s[k] == ')' || s[k] == '}' || s[k] == ']')
        {
            if(st.empty() || !ismatch(st.top(), s[k]))
                return "NO";
            else
                st.pop();
        }
    }

    return st.empty()?"YES":"NO";
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        cout << cb(s) << endl;
    }
    return 0;
}


//#include<iostream>
// #include<stack>
// #include<string>
// using namespace std;
 
// bool ArePair(char opening,char closing)
// {
// 	if(opening == '(' && closing == ')') return true;
// 	else if(opening == '{' && closing == '}') return true;
// 	else if(opening == '[' && closing == ']') return true;
// 	return false;
// }
// bool AreParanthesesBalanced(string exp)
// {
// 	stack<char>  S;
// 	for(int i =0;i<exp.length();i++)
// 	{
// 		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
// 			S.push(exp[i]);
// 		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
// 		{
// 			if(S.empty() || !ArePair(S.top(),exp[i]))
// 				return false;
// 			else
// 				S.pop();
// 		}
// 	}
// 	return S.empty() ? true:false;
// }

// int main()
// {
	
// 	string expression;
// 	cout<<"Enter an expression:  "; 
// 	cin>>expression;
// 	if(AreParanthesesBalanced(expression))
// 		cout<<"Balanced\n";
// 	else
// 		cout<<"Not Balanced\n";
// }