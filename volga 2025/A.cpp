#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<(b);i++)
#define per(i,a,b) for(int i=a;i>(b);i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
#define what_is(x) cerr << #x << ": " << x << endl;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mx = a[0];
    int count = 0;
    int need_to_be_removed = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == mx) {
            count++;
            i++;
            if (i >= n) break;
            while (i < n && a[i] < need_to_be_removed) {
                i++;
            }
            if (i >= n) break;
            mx = a[i];
            continue;
        }

        if (a[i] > mx) {
            need_to_be_removed = max(need_to_be_removed, mx);
            mx = a[i];
            continue;
        }

        need_to_be_removed = max(need_to_be_removed, a[i]);
    }

    cout << n - count << '\n';
}

int  main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; 
    cin >>t;
    while(t--) {
        solve();
    }
}