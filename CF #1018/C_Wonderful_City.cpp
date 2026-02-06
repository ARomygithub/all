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
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e3;
int n,t;
int h[mxn][mxn], a[mxn],b[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        rep(j,0,n) {
            cin >>h[i][j];
        }
    }
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    ll ans = 0;
    vector<ll> dp(2, 1e18);
    dp[0] = 0; dp[1] = a[0];
    rep(i,0,n-1) {
        vector<ll> dp_new(2, 1e18);
        rep(k1,0,2) {
            if(dp[k1]==1e18) continue;
            rep(k2,0,2) {
                bool ok = 1;
                rep(j,0,n) {
                    if(h[i][j]+k1 == h[i+1][j]+k2) {
                        ok = 0;
                        break;
                    }
                }
                if(ok) {
                    min_self(dp_new[k2], dp[k1]+a[i+1]*k2);
                }
            }
        }
        dp.swap(dp_new);
    }
    ans += min(dp[0],dp[1]);
    if(ans==1e18) {
        cout <<"-1\n";
        return;
    }
    dp[0] = 0, dp[1] = b[0];
    rep(j,0,n-1) {
        vector<ll> dp_new(2, 1e18);
        rep(k1,0,2) {
            if(dp[k1]==1e18) continue;
            rep(k2,0,2) {
                bool ok = 1;
                rep(i,0,n) {
                    if(h[i][j]+k1 == h[i][j+1]+k2) {
                        ok = 0;
                        break;
                    }
                }
                if(ok) {
                    min_self(dp_new[k2], dp[k1]+b[j+1]*k2);
                }
            }
        }        
        dp.swap(dp_new);
    }
    ll tmp = min(dp[0],dp[1]);
    if(tmp==1e18) {
        cout <<"-1\n";
        return;
    }
    ans += tmp;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}