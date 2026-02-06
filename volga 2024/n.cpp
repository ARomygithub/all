#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;;
    while(t--)
    {
        string s;
        cin >> s;
        int a = s[0] - '0';
        a -= (s[2] - '0');
        if (a == 0)
        {
            cout << s[0] << '=' << s[2];
        }
        if (a < 0)
        {
            cout << s[0] << '<' << s[2];
        }
        if (a > 0)
        {
            cout << s[0] << '>' << s[2];
        }
        cout << '\n';
    }
}