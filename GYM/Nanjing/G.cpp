#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n, w, k; cin >> n >> w >> k;
    
    vector<pii> gems(n);
    rep(i, 0, n) cin >> gems[i].first >> gems[i].second;

    vi prec(n+100);

    sort(all(gems));

    multiset<int> mem;
    int tot = 0;
    for (int i = n-1; i >= 0; i--) {
        // add to mem
        mem.insert(gems[i].second);
        tot += gems[i].second;

        // remove excess
        while ((int)mem.size() > k) {
            tot -= *mem.begin();
            mem.erase(mem.begin());
        }

        prec[i] = tot;
    }

    int dp[2][w + 100];
    memset(dp, 0, sizeof(dp));
    int ans = prec[0];
    rep(i, 1, n+1) {
        int ii = i % 2;
        rep(j, 0, w+1) {
            dp[ii][j] = dp[!ii][j];
            if (j >= gems[i-1].first) {
                dp[ii][j] = max(dp[ii][j], 
                    dp[!ii][j-gems[i-1].first] + gems[i-1].second
                );
            }

            ans = max(ans,
                dp[ii][j] + prec[i]            
            );
            // cout << dp[ii][j] << ' ';
            // cout << prec[i] << ' ';
        }
        // cout << endl;
    }

    // rep(i, 0, n) cout << prec[i] << ' '; 
    // cout << endl;

    cout << ans << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tc = 1;
    // cin >> tc;
    while(tc--) {
        solve();
    }
}