#include <bits/stdc++.h>
#define what_is cerr << #x << " is " << x << endl;
using namespace std;
using ll = long long;
#define int long long

struct State {
    int a, b, index;
};

void solve() {
    int n, k; cin >> n >> k;
    vector<State> states(n);
    for (int i = 0; i < n; i++) {
        cin >> states[i].a;
        states[i].index = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> states[i].b;
    }


    int needed = k;
    vector<int> ans(n);
    int total = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = min(needed, states[i].a / states[i].b);
        total += ans[i];
        needed -= ans[i];
    }



    if (total < k) {
        for (int i = 0; i < n; i++) {
            cout << 0 << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

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