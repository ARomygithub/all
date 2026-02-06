#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef vector<int> vi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=80;
int n;
ll p[mxn][mxn],r[mxn][mxn],d[mxn][mxn];

void solve() {
    cin >>n;
    // set<int> sc;
    rep(i,0,n) {
        rep(j,0,n) {
            cin >>p[i][j];
            // sc.insert(p[i][j]);
        }
    }
    // map<int,int> mpc, mpcr;
    // int id = 0;
    // for(auto sci : sc) {
    //     mpc[sci] = id;
    //     id++;
    // }
    rep(i,0,n) {
        rep(j,0,n-1) {
            cin >>r[i][j];
        }
    }
    rep(i,0,n-1) {
        rep(j,0,n) {
            cin >>d[i][j];
        }
    }
    vector dp(n, vector<map<int,pll>>(n));
    dp[0][0][p[0][0]] = {0,0};
    rep(i,0,n) {
        rep(j,0,n) {
            for(auto [mxc, state]: dp[i][j]) {
                ll tot = state.fi, mon = state.se*-1;
                if(i+1<n) {
                    ll totn = tot, monn = mon;
                    ll add = max(0ll, (d[i][j]-mon+mxc-1)/mxc);
                    totn += add+1;
                    monn = 1ll*mxc*add + mon - d[i][j]; 
                    int mxcn = max(1ll*mxc, p[i+1][j]);
                    if(dp[i+1][j].count(mxcn)) {
                        min_self(dp[i+1][j][mxcn], pll({totn, monn*-1}));
                    } else {
                        dp[i+1][j][mxcn] = {totn, monn*-1};
                    }
                }
                if(j+1<n) {
                    ll totn = tot, monn=mon;
                    ll add = max(0ll, (r[i][j]-mon+mxc-1)/mxc);
                    totn += add+1;
                    monn = 1ll*mxc*add + mon - r[i][j];
                    int mxcn = max(1ll*mxc, p[i][j+1]);
                    if(dp[i][j+1].count(mxcn)) {
                        min_self(dp[i][j+1][mxcn], pll({totn,monn*-1}));
                    } else {
                        dp[i][j+1][mxcn] = {totn, monn*-1};
                    }
                }
            }
        }
    }
    ll ans = 1e18;
    for(auto [mxc, state]: dp[n-1][n-1]) {
        min_self(ans, state.fi);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}