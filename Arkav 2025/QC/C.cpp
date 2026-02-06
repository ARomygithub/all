#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
int n,k;
ll m;

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.

ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}
ll inv(ll b) {
    return modpow(b, mod-2);
}
typedef vector<ll> vl;
void ntt(vl &a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vl rt(2, 1);
    for (static int k = 2, s = 2; k < n; k *= 2, s++) {
        rt.resize(n);
        ll z[] = {1, modpow(root, mod >> s)};
        rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
    }
    vi rev(n);
    rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
            ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
            a[i + j + k] = ai - z + (z > ai ? mod : 0);
            ai += (ai + z >= mod ? z - mod : z);
        }
}
vl conv(const vl &a, const vl &b) {
    if (a.empty() || b.empty()) return {};
    int sza = sz(a);
    int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
    int inv = modpow(n, mod - 2);
    vl L(a), R(b), out(n);
    L.resize(n), R.resize(n);
    ntt(L), ntt(R);
    rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
    ntt(out);
    rep(i,sza,s) {
        out[i%sza] = (out[i%sza] + out[i])%mod;
    }
    return {out.begin(), out.begin() + sza};
}

// vl conv2(const vl &a, const vl &b) {
//     int sza = sz(a);
//     vl ret = conv(a,b);
//     rep(i,sza,sz(ret)) {
//         ret[i%sza] = (ret[i%sza] + ret[i])%mod;
//     }
//     return {ret.begin(), ret.begin() + sza};
// }

void solve() {
    cin >>n >>m >>k;
    int k2 = 1<<k;
    vl poly(k2,0);
    ll sm = 0;
    rep(i,1,n+1) {
        int ai; cin >>ai;
        poly[i%k2] = (poly[i%k2] + ai)%mod;
        sm += ai;
    }
    sm %= mod;
    vl res(k2,0);
    res[0] = 1;
    ll iv = inv(modpow(sm,m));
    while(m) {
        if(m&1) {
            res = conv(res, poly);
        }
        poly = conv(poly, poly);
        m >>=1;
    }
    rep(i,1,k2+1) {
        ll cur = res[i%k2];
        cur = cur*iv%mod;
        cout <<cur <<" \n"[i==k2];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}