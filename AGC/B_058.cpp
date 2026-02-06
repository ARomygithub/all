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

const int mxn=5e3;
const ll mod=998244353;
int n;
int p[mxn+1];

void solve() {
    cin >>n;
    rep(i,1,n+1) {
        cin >>p[i];
    }
    vector<int> l(n+1,0), r(n+1,n+1);
    rep(i,1,n+1) {
        per(j,i-1,0) {
            if(p[j]>p[i]) {
                l[i] = j;
                break;
            }
        }
        rep(j,i+1,n+1) {
            if(p[j]>p[i]) {
                r[i] = j;
                break;
            }
        }
    }
    vector dp(n+1, vector<ll>(n+2,0ll));
    rep(i,1,n+1) {
        if(i==1) {
            dp[i][1] = 1;
            rep(j,2,l[i]+2) {
                dp[i][j] = dp[i-1][j];
            }
            rep(j,l[i]+2,r[i]+1) {
                dp[i][j] = 1;
            }
            rep(j,r[i]+2,n+2) {
                dp[i][j] = dp[i-1][j];
            }
            continue;
        }
        rep(j,0,n+2) {
            dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
        }
        ll temp = 0;
        rep(j,l[i]+2,r[i]+1) {
            temp = (temp + dp[i-1][j-1])%mod;
            dp[i][j] = (dp[i][j] + temp)%mod;
        }
    }
    cout <<dp[n][n+1] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}