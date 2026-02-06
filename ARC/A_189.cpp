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

const int mxn=2e5,mxa=2e5;
const ll mod = 998244353;
int n;
int a[mxn];
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

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<ll> dp(n+1,0);
    for(int i=2;i<=n;i+=2) {
        if(i==2) {
            dp[i] = 1;
        } else {
            dp[i] = dp[i-2]*(i-1)%mod;
        }
    }
    if(a[0]==0) {
        cout <<"0\n";
        return;
    }
    vi vl;
    int ls = 0;
    rep(i,1,n) {
        if(a[i]!=a[i-1]) {
            int cur = i-ls-1;
            if(cur>0) {
                vl.push_back(cur);
            }
            ls = i;
        }
    }
    int cur = n - ls - 1;
    if(cur>0) {
        vl.push_back(cur);
    }
    int sm = 0;
    rep(i,0,sz(vl)) {
        sm += (vl[i]/2);
    }
    ll ans = fct[sm];
    for(auto vli: vl) {
        ans = ans*dp[vli]%mod;
        ans = ans*ifc[vli/2]%mod;
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