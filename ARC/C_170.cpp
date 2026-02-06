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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=5e3,mxa=1e9;
const ll mod=998244353;
int n,m;
bool b[mxn];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

ll inv(ll a) {
    return fastexpo(a, mod-2);
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>b[i];
    }
    vector dp(n+1, vector<ll>());
    rep(i,0,n+1) {
        dp[i].resize(i+1, 0ll);
    }    
    dp[0][0] = 1;
    rep(i,1,n+1) {
        if(b[i-1]) {
            rep(j,0,min(i,m+1)) {
                dp[i][j+1] = (dp[i][j+1] + dp[i-1][j])%mod;
            }
        } else {
            rep(j,0,min(i,m+2)) {
                if(j!=m+1) {
                    dp[i][j+1] = (dp[i][j+1] + 1ll*(m-j)*dp[i-1][j]%mod)%mod;
                }
                dp[i][j] = (dp[i][j] + 1ll*j*dp[i-1][j]%mod)%mod;
            }
        }
    }
    ll ans=0;
    rep(i,0,n+1) {
        ans = (ans + dp[n][i])%mod;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}