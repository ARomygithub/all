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

const int mxn=1e5;
ll n,t;

ll check(ll x) {
    string sx = to_string(x);
    vector dp(sz(sx), vector(10, vector<ll>(2,0)));
    rep(i,1,sx[0]-'0') {
        dp[0][i][0] = 1;
    }
    dp[0][sx[0]-'0'][1] = 1;
    rep(i,1,sz(sx)) {
        int cur = sx[i]-'0';
        rep(j,1,10) {
            dp[i][j][0]++;
        }
        rep(last,0,10) {
            rep(j,0,2) {
                if(j==0) {
                    rep(lastn,0,10) {
                        if(lastn==last) continue;
                        dp[i][lastn][j] += dp[i-1][last][j];
                    }
                } else {
                    rep(lastn,0,cur) {
                        if(lastn==last) continue;
                        dp[i][lastn][0] += dp[i-1][last][j];
                    }
                    if(last!=cur) {
                        dp[i][cur][1] += dp[i-1][last][j];
                    }
                }
            }
        }
    }
    ll ret = 0;
    rep(i,0,10) {
        rep(j,0,2) {
            ret += dp[sz(sx)-1][i][j];
        }
    }
    return ret;
}

void solve() {
    cin >>n;
    ll l = 1;
    ll r = 1e18;
    ll ans = -1;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll chk = check(mid);
        if(chk>=n) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
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
    // cout <<check(2506230721) <<"\n";
    // cout <<check(2506230722) <<"\n";
}