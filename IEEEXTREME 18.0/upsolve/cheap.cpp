#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ll long long
#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>
#define debug(x)    cout << #x << " : " << x << endl;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MOD = 1000000007;
//const int MOD = 998244353;

typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};
using pii = pair<int,int>;

void solve() {
    string s; cin >> s;
    int n = s.length();
    HashInterval ha(s);

    gp_hash_table<ull, pii> mp;
    vi ans(n+5, INT_MAX);


    for (int len = 1; len <= n; len++) {
        mp.clear();
    
        for(int i = 0; i + len - 1 < n; i++) {
            ull cur = ha.hashInterval(i,i+len).get();
            if(mp.find(cur)!=mp.end()) {
                auto [cnt, prev] = mp[cur];
                cnt -= min(len-1, i-prev);
                mp[cur] = {cnt, i};
            } else {
                mp[cur] = {n-(len-1), i};
            }
        }


        for(const auto &x : mp) {
            // check for new count
            // cout << x.first << ' ' << len << " : ";
            // for(auto ppp: x.second) {
            //     cout << ppp << ' ';
            // }cout << '\n';
            int cnt = x.second.first;
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
    // ios::sync_with_stdio(false); cin.tie(NULL);
    int tc = 1;
    // cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}