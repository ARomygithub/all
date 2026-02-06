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

const int mxn=1e5;
const ll mod=998244353;
int n,k;

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

void solve() {
    cin >>n >>k;
    vector<vector<ll>> dp(1+1);
    dp[0].resize(min(0*6,n)+1);
    dp[0][0] = 1;
    ll ans=0;
    ll iv6 = fastexpo(6ll,mod-2);
    ll ivi= iv6;
    rep(i,1,min(n,k)+1) {
        dp[1] = vector<ll>(1+min(i*6,n),0);
        rep(j,i,min(i*6,n)+1) {
            // cout <<dp[1][j] <<" \n"[j==min(i*6,n)];
            per(ki,j-1,max(j-7,-1)) {
                if(ki>=sz(dp[0])) continue;
                dp[1][j] = (dp[1][j]+dp[0][ki])%mod;
            }
        }
        if(i*6>=n && i<=n) {
            ll tempi = dp[1][n]*ivi%mod;
            // cout <<tempi <<"\n";
            ans = (ans+tempi)%mod;
        }
        dp[0].swap(dp[1]);
        ivi = iv6*ivi%mod;
    }
    ll ivk = fastexpo(k,mod-2);
    ans = ans*ivk%mod;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}