#include <bits/stdc++.h>
#define what_is cerr << #x << " is " << x << endl;
using namespace std;
using ll = long long;


void solve() {
    int n; cin >> n;
    vector<ll> dvals;
    map<ll,int> cnt;
    for (int i = 0; i < n; i++)
    {
        ll el; cin >> el;
        if (cnt[el]) dvals.push_back(el);
        cnt[el] = 1 - cnt[el];
    }
    sort(dvals.begin(), dvals.end());
    if (dvals.size() < 4)
    {
        cout << "NO\n";
    }
    else
    {
        ll a,b,c,d;
        int le = dvals.size();
        a = dvals[0];
        b = dvals[1];
        c = dvals[le-1];
        d = dvals[le-2];
        cout << "YES\n";

        auto print = [](ll x, ll y) {
            cout << x << ' ' << y <<  ' ';
        };
        if ((d - a) * (c - b) > (d - b) * (c - a))
        { 
            // y1 = d, y2 = a
            // x2 = c, x1 = b
            print(b, d);
            print(b, a);
            print(c, d);
            print(c, a);
        }
        else
        {
            // y1 = d, y2 = b
            // x2 = c, x1 = a
            print(a, d);
            print(a, b);
            print(c, d);
            print(c, b);
        }
        cout << '\n';
    }
}

signed main()
{
    // t = 1;
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}