#include <bits/stdc++.h>
#define what_is cerr << #x << " is " << x << endl;
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&] (int c) -> bool {
        
    };

    int mx = *max_element(a.begin(), a.end());
    int lo = 0, hi = mx;
    while (lo < hi) {
        int mid = (hi + lo + 1) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    if (!check(lo)) {
        cout << -1 << '\n';
        return;
    }

    cout << lo << '\n';
}

signed main()
{
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}