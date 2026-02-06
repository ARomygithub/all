#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
#define pll pair<ll,ll>

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e6;
const ll mod=998244353;
const int mxa=1e6;
ll iv[mxa+1];
int n,t;
string a,b;

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

void init_fac() {
    iv[1]=1;
    for(int i=2;i<=mxa;i++) {
        iv[i] = mod - mod/i*iv[mod%i]%mod;
    }
}

void solve() {
    cin >>n;
    cin >>a >>b;
    int m=0;
    for(int i=0;i<n;i++) {
        if(a[i]!=b[i]) {
            m++;
        }
    }
    if(m==0) {
        cout <<"0\n";
        // cout <<"tes\n";
        return;
    }
    if(n==1) {
        cout <<"1\n";
        return;
    }
    vector<pll> dp(n+1,{0,0});
    ll x1=-1;
    dp[1] = {1,0};
    for(int i=2;i<=n;i++) {
        ll temp = dp[i-1].fi*n%mod;
        ll temp2 = dp[i-2].fi*(i-1)%mod;
        temp = (temp-temp2+mod)%mod;
        dp[i].fi = temp*iv[n-i+1]%mod;

        temp = dp[i-1].se*n%mod;
        temp = (temp-n+mod)%mod;
        temp2 = dp[i-2].se*(i-1)%mod;
        temp = (temp-temp2+mod)%mod;
        dp[i].se = temp*iv[n-i+1]%mod;
        // cout <<dp[i] <<"\n";
    }
    // x1 = fastexpo((dp[n]-dp[n-1]+mod)%mod,mod-2);
    ll p,q;
    p = (dp[n].fi-dp[n-1].fi+mod)%mod;
    q = (dp[n-1].se+1)%mod;
    q = (q-dp[n].se+mod)%mod;
    x1 = q*fastexpo(p,mod-2)%mod;
    ll ans = dp[m].fi*x1%mod;
    ans = (ans+dp[m].se)%mod;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_fac();
    cin >>t;
    while(t--) {
        solve();
    }
}