#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ll long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>
#define debug(x)    cout << #x << " : " << x << endl;
#define sz(x) (int) (x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)

const int MOD = 1000000007;
//const int MOD = 998244353;

const ll MODMOD = 1000000007;
const ll popow = 816253;

void solve() {
    string s; cin >> s;
    int n = s.length();

    vector<unordered_map<ll, vi>> mp(n+2);
    
    
    for(int i = 0; i < n; i++) {
        ll pval = 0;
        for(int j = i; j < n; j++) {
            pval = (pval * popow + s[j]) % MODMOD;
            if(j-i) {
                auto& vid = mp[j-i+1][pval];
                int len = j-i+1;
                while(sz(vid)>=2 && i-vid[sz(vid)-2]+1 <=len) {
                    vid.pop_back();
                } 
                mp[j-i+1][pval].push_back(i);
            } 
        }
    }

    vi ans(n+5, INT_MAX);

    for (int len = 2; len <= n; len++) {
        for(const auto &x : mp[len]) {
            // check for new count
            // cout << x.first << ' ' << len << " : ";
            // for(auto ppp: x.second) {
            //     cout << ppp << ' ';
            // }cout << '\n';
            int cnt = n;
            int prev = -10000000;
            for(const auto &y : x.second) {
                cnt -= min(len - 1, y - prev);
                prev = y;
            }
            ans[cnt] = min(ans[cnt], len);
        }
    }
    
    ans[n] = 1;

    for(int i = 1; i <= n; i++) {
        if (ans[i] == INT_MAX) {
            cout << "0 ";
        } else {
            cout << ans[i] << " ";
        }
    }
    cout << '\n';

}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int tc = 1;
    // cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}