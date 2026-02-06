#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>
#define debug(x)    cout << #x << " : " << x << endl;

const int MOD = 1000000007;
//const int MOD = 998244353;

const int NMAX = 1e6 + 5;

int par[NMAX];
struct pardata {
    int fi;
    int la;
    bool active;
};
pardata p[NMAX];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    par[x] = y;
    p[y].fi = min(p[y].fi, p[x].fi);
    p[y].la = max(p[y].la, p[x].la);
}

void init() {
    for (int i = 0; i < NMAX; i++) par[i] = i;
    for (int i = 0; i < NMAX; i++) {
        p[i].fi = i;
        p[i].la = i;
        p[i].active = false;
    }
}


void solve() {
    int n, po;
    cin >> n >> po;
    vi a(n);
    forn(i, n) cin >> a[i];

    init();

    vector<pair<int, int>> validx; 
    forn(i, n) validx.push_back({a[i], i});
    sort(validx.begin(), validx.end());
    reverse(validx.begin(), validx.end());
    int ans = 0;

    for (int i = 0; i < validx.size(); i++) {
        for (int j = i; j < validx.size() && validx[i].first == validx[j].first; j++) {
            auto x = validx[j];
            p[x.second].active = true;
            // merge with left & right
            if (p[find(x.second - 1)].active) join(x.second, x.second - 1);
            if (p[find(x.second + 1)].active) join(x.second, x.second + 1);
            
        }

        for (int j = i; j < validx.size() && validx[i].first == validx[j].first; j++) {
            auto x = validx[j];
            // search for left & right
            int l = p[find(x.second)].fi;
            int r = p[find(x.second)].la;

            // search for +1 left and +1 right
            int l2 = l, r2 = r;
            if (l > 1 && p[find(l - 2)].active) l2 = p[find(l - 2)].fi;
            if (r < n - 2 && p[find(r + 2)].active) r2 = p[find(r + 2)].la;

            // combine
            ans = max(ans, validx[j].first * (r - l + 1));
            if (validx[j].first <= po) {
                ans = max(ans, validx[j].first * (r2 - l + 1));
                ans = max(ans, validx[j].first * (r - l2 + 1));
            }
            i = j;
        }


    }

    cout << ans << endl;
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