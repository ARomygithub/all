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
const ll mod = 998244353;
ll n,m,k;

ll fastexpo(ll a, ll b) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = ret*a%mod;
        a = a*a%mod;
        b >>=1;
    }
    return ret;
}

ll inv(ll x) {
    return fastexpo(x,mod-2);
}

void solve() {
    cin >>n >>m >>k;
    vector<ll> dp(k+1, 0);
    dp[0] = 1;
    rep(i,1,k+1) {
        vector<ll> dp_new(k+1,0);
        rep(j,0,k+1) {
            dp_new[j] = (dp_new[j] + dp[j]*j%mod)%mod;
            if(j+1<k+1 && n-j>0) {
                dp_new[j+1] = (dp_new[j+1] + dp[j]*(n-j)%mod)%mod;
            }
        }
        dp.swap(dp_new);
    }
    ll ans = 0;
    ll ivm = inv(m);
    // cout <<ivm <<"\n";
    rep(i,1,k+1) {
        // cout <<dp[i] <<"\n";
        ans = (ans + dp[i]*fastexpo(ivm,i)%mod)%mod;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}