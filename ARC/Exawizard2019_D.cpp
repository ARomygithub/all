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

const int mxn=200;
const ll mod=1e9+7;
const int mxa=1e5;
ll fct[mxa+1], ifc[mxa+1], iv[mxa+1];
int n,x;

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
    cin >>n >>x;
    vector<int> s(n);
    rep(i,0,n) {
        cin >>s[i];
    }
    sort(s.begin(),s.end());
    vector<ll> dp(max(s[n-1],x)+1,0ll);
    dp[x] = 1;
    per(i,n-1,-1) {
        rep(val,s[i],sz(dp)) {
            auto itr = upper_bound(s.begin(), s.end(), val);
            int vali = val%s[i];
            int udh = s.end()-itr;
            dp[vali] = (dp[vali] + dp[val]*iv[n-udh]%mod)%mod;
            // if(dp[val]) {
            //     cout <<bebas <<" " <<udh <<endl;
            //     cout <<dp[val] <<" " <<temp <<endl;
            // }
        }
    }
    dp[x] = (dp[x] -1+mod)%mod;
    ll ans = 0;
    rep(i,0,s[0]) {
        ans = (ans + dp[i]*i%mod)%mod;
    }
    ans = ans*fct[n]%mod;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_fac();
    solve();
}