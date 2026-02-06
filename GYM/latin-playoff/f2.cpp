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

const int mxn=2e5;
int n;

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
typedef vector<ll> vl;
ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}
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
    int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
    int inv = modpow(n, mod - 2);
    vl L(a), R(b), out(n);
    L.resize(n), R.resize(n);
    ntt(L), ntt(R);
    rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
    ntt(out);
    return {out.begin(), out.begin() + s};
}

void solve() {
    cin >>n;
    int d = 0;
    set<pii> sp;
    vector<vl> v;
    bool ada0 = 0;
    rep(i,0,n) {
        int g,r; cin >>g >>r;
        d = gcd(d, r);
        vl poly(g+1,0);
        poly[0] = 1;
        poly[g] = 1;
        v.push_back(poly);
        sp.insert({g+1,i});
        ada0 = ada0 || (g==0);
    }
    if(n==1) {
        cout <<"N\n";
        return;
    }
    while(sz(sp)>=2) {
        auto [szi, i] = *sp.begin(); sp.erase(sp.begin());
        auto [szj, j] = *sp.begin(); sp.erase(sp.begin());
        v[i] = conv(v[i],v[j]);
        v[j].clear();
        // rep(k,0,sz(v[i])) {
        //     v[i][k] = min(1ll,v[i][k]);
        // }
        sp.insert({sz(v[i]),i});
    }
    int id = (sp.begin()->se);
    int sg = sz(v[id])-1;
    rep(i,0,sz(v[id])) {
        if(!ada0 && (i==0 || i==sg)) {
            continue;
        }
        // cout <<i <<" " <<v[id][i] <<endl;
        if(v[id][i]==0) continue;
        int dif = abs(sg-i*2);
        if((dif%d)==0) {
            cout <<"Y\n";
            return;
        }
    }
    cout <<"N\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}