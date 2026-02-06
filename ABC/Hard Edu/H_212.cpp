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

const int mxn=1e5;
const ll mod=998244353;
int n,k;

ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}

ll invi(ll b) {
    return modpow(b,mod-2);
}

void FST(vector<ll>& a, bool inv) {
    for (int n = sz(a), step = 1; step < n; step *= 2) {
        for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
            ll &u = a[j], &v = a[j + step]; tie(u, v) =
                // inv ? pii(v - u, u) : pii(v, u + v); // AND
                // inv ? pii(v, u - v) : pii(u + v, u); // OR /// include-line
                pll((u + v)%mod, (u - v+mod)%mod);                   // XOR /// include-line
        }
    }
    if (inv) for (ll& x : a) x = x*invi(sz(a))%mod; // XOR only /// include-line
}
// vi conv(vi a, vi b) {
//     FST(a, 0); FST(b, 0);
//     rep(i,0,sz(a)) a[i] *= b[i];
//     FST(a, 1); return a;
// }

vector<ll> geom(vector<ll> a, ll ni) {
    FST(a,0);
    rep(i,0,sz(a)) {
        if((a[i]%mod)==1) {
            a[i] = a[i]*ni%mod;
        } else {
            ll tmp = (modpow(a[i],ni+1)-a[i]+mod)%mod;
            ll bwh = (a[i]-1+mod)%mod;
            a[i] = tmp*invi(bwh)%mod;
        }
    }
    FST(a,1);
    return a;
}

void solve() {
    cin >>n >>k;
    vector<ll> c(1<<16,0);
    rep(i,0,k) {
        int ai; cin >>ai;
        c[ai]++;
    }
    auto cpw = geom(c, n);
    ll ans = 0;
    rep(i,1,sz(cpw)) {
        ans = (ans + cpw[i])%mod;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}