#include <bits/stdc++.h>
#define what_is cerr << #x << " is " << x << endl;
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int num_people = 0;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        int num; cin >> num;
        if (c == 'P') {
            num_people += num;
        } else {
            int sisa = max(0, num - num_people);
            num_people = max(0, num_people - num);
            if (sisa >= 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

signed main()
{
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}