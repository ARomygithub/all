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

const int mxn=1e2;
const ll mod = 1e9+7;
int n,m,k;
ll a[mxn];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = ret*a%md;
        a = a*a%md;
        b >>=1;
    }
    return ret;
}

ll inv(ll a) {
    return fastexpo(a,mod-2);
}

void solve() {
    cin >>n >>m >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<pii> e;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        e.push_back({u,v});
    }
    vector<vector<vector<ll>>> dp;
    vector dp0(n, vector<ll>(n,0));
    rep(i,0,n) {
        dp0[i][i] = 1;
    }
    map<int,int> mp;
    mp[0] = sz(dp);
    dp.push_back(dp0);
    vector dp1(n, vector<ll>(n,0));
    ll iv2 = inv(2);
    ll ivm = inv(m);
    rep(i,0,m) {
        auto [u,v] = e[i];
        rep(j,0,n) {
            if(j==u || j==v) continue;
            dp1[j][j] = (dp1[j][j] + ivm)%mod;
        }
        dp1[u][u] = (dp1[u][u] + iv2*ivm%mod)%mod;
        dp1[u][v] = (dp1[u][v] + iv2*ivm%mod)%mod;
        dp1[v][u] = (dp1[v][u] + iv2*ivm%mod)%mod;
        dp1[v][v] = (dp1[v][v] + iv2*ivm%mod)%mod;
    }
    mp[1] = sz(dp);
    dp.push_back(dp1);
    int ct = 1;
    while(k>=(1<<ct)) {
        ct++;
    }
    int u = 1;
    per(bit,ct-2,-1) {
        vector dpi(n, vector<ll>(n,0));
        int mpu = mp[u];
        rep(i,0,n) {
            rep(j,0,n) {
                rep(l,0,n) {
                    dpi[i][j] = (dpi[i][j] + dp[mpu][l][j]*dp[mpu][i][l]%mod)%mod;
                }
            }
        }
        u *=2;
        if((k>>bit)&1) {
            vector dpin(n, vector<ll>(n,0));
            rep(i,0,n) {
                rep(j,0,n) {
                    rep(l,0,n) {
                        dpin[i][j] = (dpin[i][j] + dpi[l][j]*dp[1][i][l]%mod)%mod;
                    }
                }
            }
            u++;
            dpi.swap(dpin);
        }
        mp[u] = sz(dp);
        dp.push_back(dpi);
    }
    vector<ll> ans(n,0);
    rep(i,0,n) {
        rep(j,0,n) {
            ans[i] = (ans[i] + dp[min(sz(dp)-1,k)][i][j]*a[j]%mod)%mod;
        }
    }
    rep(i,0,n) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}