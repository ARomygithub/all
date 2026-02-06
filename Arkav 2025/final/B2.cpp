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

const int mxm=2e5,mxa=401;
const ll mod = 1e9+7;
int n,m;
ll fct[mxa+1],ifc[mxa+1],iv[mxa+1];

void init_fac() {
    iv[1]=1;
    for(int i=2;i<=mxa;i++) {
        iv[i] = mod - mod/i*iv[mod%i]%mod;
    }
    fct[0]=1, ifc[0]=1;
    for(int i=1;i<=mxa;i++) {
        fct[i]=fct[i-1]*i%mod;
        ifc[i]=ifc[i-1]*iv[i]%mod;
    }
}

ll C(ll a, ll b) {
    if(a<b || a<0 || b<0) return 0;
    ll ret=fct[a];
    ret = ret*ifc[b] %mod;
    ret = ret*ifc[a-b] %mod;
    return ret;
}

void solve() {
    cin >>n >>m;
    assert(n <= (mxa/2));
    assert(m <= mxm);
    vector dp(n+1, vector<ll>(n+1,0));
    rep(j,0,n+1) {
        dp[0][j] = 1;
    }
    rep(i,1,n+1) {
        rep(j,1,n+1) {
            if(i>=j) {
                rep(k,1,j+1) {
                    ll cur = C(j,k)*dp[i-k][j]%mod;
                    if(k%2) {
                        dp[i][j] = (dp[i][j] + cur)%mod;
                    } else {
                        dp[i][j] = (dp[i][j] - cur + mod)%mod;
                    }
                }
            } else {
                rep(k,1,i*2+2) {
                    ll cur = (j>=k? dp[i][j-k]: dp[i][k-j-1]);
                    cur = cur*C(i*2+1, k)%mod;
                    if(k%2) {
                        dp[i][j] = (dp[i][j] + cur)%mod;
                    } else {
                        dp[i][j] = (dp[i][j] - cur + mod)%mod;
                    }
                }
            }
            assert(dp[i][j]>=0 && dp[i][j]<mod);
        }
    }
    if(m>n) {
        // dp[n].resize(m+1,0);
        rep(j,n+1,m+1) {
            dp[n].push_back(0);
        }
        int i = n;
        rep(j,n+1,m+1) {
            rep(k,1,i*2+2) {
                ll cur = (j>=k? dp[i][j-k]: dp[i][k-j-1]);
                cur = cur*C(i*2+1, k)%mod;
                if(k%2) {
                    dp[i][j] = (dp[i][j] + cur)%mod;
                } else {
                    dp[i][j] = (dp[i][j] - cur + mod)%mod;
                }
            }    
            assert(dp[i][j]>=0 && dp[i][j]<mod);
        }
    }
    cout <<dp[n][m] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_fac();
    solve();
}