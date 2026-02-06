#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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

const ll root_1 = inv(root);
const int root_pw = 1 << 23;

void fft(vector<ll> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = inv(n);
        for (auto & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

vl pwr(const vl &a, ll mi) {
    if (a.empty()) return {};
    int sza = sz(a);
    int s = sz(a), B = 32 - __builtin_clz(s), n = 1 << B;
    int inv = modpow(n, mod - 2);
    vl L(a), out(n);
    L.resize(n);
    fft(L, 0);
    // rep(i,0,n) out[-i & (n - 1)] = modpow(L[i],mi) * inv % mod;
    rep(i,0,n) {
        out[i] = modpow(L[i],mi) * inv %mod;
    }
    // reverse(out.begin()+1,out.end());
    fft(out, 1);
    // rep(i,sza,s) {
    //     out[i%sza] = (out[i%sza] + out[i])%mod;
    // }
    return {out.begin(), out.begin() + sza};
}

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
    vl res = pwr(poly, m);
    ll iv = inv(modpow(sm,m));
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