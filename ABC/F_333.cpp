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

const int mxn=3e3;
const ll mod=998244353;
int n;

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
    cin >>n;
    vector dp(n, vector<ll>());
    vector s1(n, vector<ll>());
    vector s2(n, vector<ll>());
    rep(i,0,n) {
        dp[i].resize(i+1);
        s1[i].resize(i+1);
        s2[i].resize(i+1);
    }
    dp[0][0] = 1;
    ll i2 = 1;
    rep(i,1,n) {
        vector<ll> c(i+1);
        i2 =i2*2%mod;
        c[0] = i2*inv((i2*2-1+mod)%mod)%mod;
        rep(j,1,i+1) {
            c[j] = c[j-1]*inv(2)%mod;
        }
        s1[i][0] = 0, s2[i][0] = 0;
        rep(j,1,i+1) {
            s2[i][0] = (s2[i][0] + c[j]*dp[i-1][i-j]%mod)%mod;
        }
        dp[i][0] = (s1[i][0] + s2[i][0])%mod;
        rep(j,1,i+1) {
            s1[i][j]=0, s2[i][j]=0;
            ll temp = c[i]*dp[i-1][j-1]%mod;
            ll s2temp = (s2[i][j-1]-temp+mod)%mod;
            s2[i][j] = (s2[i][j] + s2temp*inv(2)%mod)%mod;
            s1[i][j] = (s1[i][j] + temp*fastexpo(2ll,i)%mod)%mod;
            s1[i][j] = (s1[i][j] + s1[i][j-1]*inv(2)%mod)%mod;
            dp[i][j] = (s1[i][j] + s2[i][j])%mod;
        }
    }
    rep(i,0,n) {
        cout <<dp[n-1][i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}