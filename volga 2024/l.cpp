#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int r = n % 3;
    if (r == 1 or r == 0)
        cout << (2 * (n - r)) / 3 + (n + 2 * r + 1) / 2 << '\n';
    if (r == 2)
    {
        int initial = (2 * (n - r)) / 3;
        int sisa =  (n + 2 * r - 3);
        cout << initial + 1 + (sisa + 1) / 2;
    }
}