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

const int mxn=1e6,mxa=1e6;
const ll mod=998244353;
int n,t;
ll fct[mxa+1],iv[mxa+1],ifc[mxa+1];

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

void solve() {
    // cin >>n;
    vector dp(n+1, vector<ll>());
    rep(i,2,n+1) {
        dp[i].resize(i-1,0);
    }
    if(n>=2) {
        dp[2][0] = 1;
    }
    rep(i,3,n+1) {
        rep(j,0,i-1) {
            if(j<i-2) {
                dp[i][j] = (dp[i-1][j]+dp[i][j])%mod;
            }
            if(j>0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]*iv[i-1]%mod*(j+1)%mod*iv[j]%mod)%mod;
            } else {
                dp[i][j] = (dp[i][j] + iv[i-1])%mod;
            }
            // cout <<"tes" <<endl;
        }
    }
    ll ans = 0;
    rep(i,2,n+1) {
        ll temp = fct[n]*iv[i]%mod;
        rep(j,0,i-1) {
            ans = (ans + temp*dp[i][j]%mod)%mod;
        }
    }
    ans = (ans + fct[n]*n%mod)%mod;
    // cout <<ans <<" " <<ans*ifc[n]%mod <<"\n";
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    init_fac();
    // while(t--) {
    //     solve();
    // }
    rep(t,1,101) {
        n = t;
        cout <<t <<" ";
        solve();
    }
}