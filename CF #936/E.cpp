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

const int mxn=2e5,mxa=2e5;
const ll mod = 1e9+7;
int n,t;
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
    int m1, m2;
    cin >>n >>m1 >>m2;
    vector<int> p(m1), s(m2);
    rep(i,0,m1) {
        cin >>p[i];
    }
    rep(i,0,m2) {
        cin >>s[i];
    }
    if(p[m1-1]!=s[0] || p[0]!=1 || s[m2-1]!=n) {
        cout <<"0\n";
        return;
    }
    ll ans = 1;
    ll ans1 = 1;
    if(m1>=2) {
        ans = ans*fct[p[1]-p[0]-1]%mod;
    }
    rep(i,1,m1-1) {
        ans1 = ans1*C(p[i+1]-2,p[i]-1)%mod;
        ans = ans*fct[p[i+1]-p[i]-1]%mod;
    }
    ll ans2 = 1;
    if(m2>=2) {
        ans = ans*fct[s[m2-1]-s[m2-2]-1]%mod;
    }
    per(i,m2-2,0) {
        ll len = n-s[i];
        ll lenn = n - s[i-1];
        // cout <<len <<" " <<lenn <<"\n";
        ans2 = ans2*C(lenn-1,len)%mod;
        ans = ans*fct[s[i]-s[i-1]-1]%mod;
    }
    ans = ans*C(n-1,p[m1-1]-1)%mod;
    ans = ans*ans1%mod;
    ans = ans*ans2%mod;
    // cout <<ans1 <<"\n";
    // cout <<ans2 <<"\n";
    // cout <<C(n-1,p[m1-1]-1) <<"\n";
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init_fac();
    while(t--) {
        solve();
    }
}