#include <iostream>
#include <string>
using namespace std;

class test{
    private: 
        string str;

    public:
        void push(string s)
        {
            str = s;
        }

        void display()
        {
            cout << str;
        }
};
int main()
{
    string str;
    getline(cin, str);

    test e;
    e.push(str);
    e.display();
    return 0;
}