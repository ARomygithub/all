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

const int mxn=3000,mxa=3000;
const ll mod = 1e9+7;
int n,m;
string s;
int pref[mxn+1];
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
    cin >>s;
    vector<pii> v0(m);
    rep(i,0,m) {
        cin >>v0[i].fi >>v0[i].se;
    }
    vector<pii> v;
    rep(i,0,m) {
        if(sz(v)) {
            if(v0[i].fi==v.back().fi) {
                // cout <<v.back().se <<"\n";
                max_self(v.back().se, v0[i].se);
                // cout <<v.back().se <<"\n";
            } else {
                if(v0[i].se>v.back().se) {
                    v.push_back(v0[i]);
                }
            }
        } else {
            v.push_back(v0[i]);
        }
    }
    rep(i,0,n) {
        pref[i+1] = pref[i] + (s[i]=='1');
    }
    vector<ll> dp(pref[n]+1,0);
    dp[pref[v[0].fi-1]] = 1;
    rep(i,0,sz(v)) {
        vector<ll> dp_new(pref[n]+1,0);
        if(i>0 && v[i].fi>v[i-1].se) {
            rep(j,0,pref[n]+1) {
                if(j==pref[v[i].fi-1]) continue;
                dp[pref[v[i].fi-1]] = (dp[pref[v[i].fi-1]] + dp[j])%mod;
                dp[j] = 0;
            }
        }
        int lnxt = i+1<sz(v)?v[i+1].fi:v[i].se+1;
        int r = v[i].se;
        int l = v[i].fi;
        rep(j,0,pref[n]+1) {
            if(dp[j]==0) continue;
            int ctl = max(pref[r]-j-max((r-lnxt+1),0),0);
            int ctr = min(pref[r]-j,min(lnxt,r+1)-l);
            rep(k,ctl,ctr+1) {
                dp_new[j+k] = (dp_new[j+k] + dp[j]*C(min(lnxt,r+1)-l,k)%mod)%mod;
            }
        }
        dp.swap(dp_new);
    }
    ll ans = 0;
    rep(i,0,pref[n]+1) {
        ans = (ans+dp[i])%mod;
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