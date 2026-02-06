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

const int mxn=1e6;
const ll mod=998244353;
const int mxa=2e6;
ll fct[mxa+1], ifc[mxa+1], iv[mxa+1];
ll n,m;

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
    ll ans = 0;
    vector<ll> n1(m+1),m1(n+1);
    n1[1] = n-1;
    rep(i,2,m+1) {
        n1[i] = n1[i-1]*(n-1)%mod;
    }
    m1[1] = m-1;
    rep(i,2,n+1) {
        m1[i] = m1[i-1]*(m-1)%mod;
    }
    ans = (ans + (n-1)*n)%mod;
    rep(lm,1,n) {
        ll ct = (n-lm-1)*2 + 1;
        ll temp = m1[lm]*ct*2%mod;
        ans = (ans+temp)%mod;
        ll temp2 = m1[lm]*2%mod;
        ans = (ans+temp2)%mod;
    }
    ans = (ans + m1[n])%mod;
    ans = (ans + (m-1)*(m))%mod;
    rep(lm,1,m) {
        ll ct = (m-lm-1)*2 + 1;
        ll temp = n1[lm]*ct*2%mod;
        ans = (ans+temp)%mod;
        ll temp2 = n1[lm]*2%mod;
        ans = (ans+temp2)%mod;
    }
    ans = (ans + n1[m])%mod;
    ans = (ans - C(m+n-1,n-1) + mod)%mod;
    ans = (ans - C(m+n-1,n) + mod)%mod;
    ans = (ans - C(m+n,n) + mod)%mod;
    ans = (ans+4)%mod;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_fac();
    solve();
}