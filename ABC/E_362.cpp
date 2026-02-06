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

const int mxn=80;
const ll mod=998244353;
int n;
ll a[mxn], iv[mxn+1];

void init_fac() {
    iv[1] = 1;
    for(int i=2;i<=mxn;i++) {
        iv[i] = mod - mod/i*iv[mod%i]%mod;
    }    
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<ll> ans(n+1,0);
    ans[1] = n;
    rep(i,0,n) {
        map<pll,ll> mp;
        rep(j,i+1,n) {
            map<pll, ll> add;
            for(auto [k,v]: mp) {
                auto [last, dif] = k;
                if(last+dif==a[j]) {
                    add[{last+dif,dif}] = (add[{last+dif,dif}]+v)%mod;
                    ll len = (last+dif-a[i])/dif + 1;
                    ans[len] = (ans[len] + v)%mod;
                }
            }
            for(auto [k,v]: add) {
                mp[k] = (mp[k] + v)%mod;
            }
            if(a[j]==a[i]) continue;
            mp[{a[j],a[j]-a[i]}] = (mp[{a[j],a[j]-a[i]}] + 1)%mod;
            ans[2] = (ans[2] + 1)%mod;
        }
    }
    map<ll, int> mp;
    rep(i,0,n) {
        mp[a[i]]++;
    }
    for(auto [k,v]: mp) {
        rep(i,2,v+1) {
            ll mul = 1ll;
            per(j,i,0) {
                mul = mul*(v-i+j)%mod;
                mul = mul*iv[j]%mod;
            }
            ans[i] = (ans[i] + mul)%mod;
        }
    }
    rep(i,1,n+1) {
        cout <<ans[i] <<" \n"[i==n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_fac();
    solve();
}