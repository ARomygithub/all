#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i= a; i < (b);i++)
#define per(i,a,b) for(int i= a; i > (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> ans(n);
    for (int i = 1; i <= n; i++) {
        ans[i - 1] = i;
    }

    if (n == 2) {
        if (m & 1) {
            cout << "2 1\n";
        } else {
            cout << "1 2\n";
        }
        return;
    }

    int shift = min(m, n);
    for (int i = 0; i < shift; i++) {
        cout << ans[n - 1 - i] << ' ';
    }

    for (int i = 0; i < n - shift; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}