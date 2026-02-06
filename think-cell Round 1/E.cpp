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

const int mxn=1e6,mxa=1e6;
const ll mod = 998244353;
int n,t;
ll fct[mxn+1],ifc[mxn+1],iv[mxn+1];

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
    cin >>n;
    int k = (n-1)/2;
    vector<ll> ans(k,0);
    rep(i,0,k) {
        for(int j=0;j<n;j+=(i+1)*2) {
            ans[i] = (ans[i] + C(n,j))%mod;
            if(j>0) {
                ans[i] = (ans[i] - C(n-j+(i+1)*2-1,(i+1)*2-1)+mod)%mod;
            }
        }
    }
    rep(i,0,k) {
        cout <<ans[i] <<" \n"[i==k-1];
    }
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