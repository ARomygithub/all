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

const int mxn=5e6,mxa=5e6;
const ll mod = 998244353;
ll n,a,b,c;
ll fct[mxa+1], ifc[mxa+1], iv[mxa+1];

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

void getDp(vector<ll>& dp, ll m) {
    dp[0] = 1;
    rep(i,1,n+1) {
        if(i<=m) {
            dp[i] = dp[i-1]*2ll%mod;
        } else {
            ll temp = dp[i-1]*2ll%mod;
            temp = (temp - C(i-1,m) + mod)%mod;
            dp[i] = temp;
        }
    }
}

void solve() {
    cin >>n >>a >>b >>c;
    vector<ll> dpa(n+1),dpb(n+1),dpc(n+1);
    getDp(dpa, a);
    getDp(dpb, b);
    getDp(dpc, c);
    ll ans = 0;
    rep(i,0,n+1) {
        ll temp = dpa[n-i]*dpb[n-i]%mod*dpc[n-i]%mod;
        if(i%2) {
            ans = (ans - temp*C(n,i)%mod + mod)%mod;
        } else {
            ans = (ans + temp*C(n,i)%mod)%mod;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_fac();
    solve();
}