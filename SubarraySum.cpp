#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> v,s,z;
    int n;
    cout << "enter array length: ";
    cin >> n;

    cout << "Enter array :\n";
    for(int i = 0; i < n; i++)    
        cin >> v[i];

    if(v[0] == 0)
        z[0] = 1;
    else
        z[0] = 0;

    s[0] = v[0];

    for(int i = 1; i < n; i++)
    {
        if(v[i] == 0)
            z[i] = z[i-1] + 1;
        else
            z[i] = z[i-1];

        s[i] = s[i-1] + v[i];
    }

    int q;
    cin >> q;
    while(q--)
    {
        int l,r,x;
        cout << "Enter starting index: ";
        cin >> l;
        cout << "Enter ending index: ";
        cin >> r;
        cout << "Enter new element: ";
        cin >> x;

        int res = s[r-1] - s[l-1] + (z[r-1] + z[l-1])*10;
        cout << res << endl;
    }

    return 0;
}
