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
const ll mod= 998244353;
int n,m;
string a,b;
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
    cin >>n >>m;
    cin >>a;
    cin >>b;
    vi cta(26,0);
    vi ctb(26,0);
    rep(i,0,n) {
        cta[a[i]-'A']++;
    }
    rep(i,0,m) {
        ctb[b[i]-'A']++;
    }
    vector<ll> dp(1, 1);
    rep(i,0,26) {
        if(i<25) {
            int szi = min(cta[i],ctb[i+1]);
            vector<ll> dp_new(szi+1, 0);
            int idx = 0;
            ll temp = 0;
            rep(j,0,sz(dp_new)) {
                while(idx<sz(dp) && ctb[i]-idx+j>=cta[i]) {
                    temp = (temp+dp[idx])%mod;
                    idx++;
                }
                dp_new[j] = temp*C(cta[i],j)%mod;
            }
            dp.swap(dp_new);
        } else {
            rep(j,0,sz(dp)) {
                if(ctb[i]-j < cta[i]) {
                    dp[j] = 0;
                }
            }
        }
    }
    ll ans = 0;
    rep(i,0,sz(dp)) {
        ans = (ans + dp[i])%mod;
    }
    ans = ans*fct[n]%mod;
    rep(i,0,26) {
        ans = ans*ifc[cta[i]]%mod;
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