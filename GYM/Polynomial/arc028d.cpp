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

const int mxn=2e3;
const ll mod = 1e9+7;
int n,m,q;
int a[mxn];
using piii = pair<pii,int>;

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);  // (^ 10% faster if double)
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vi rev(n);
    rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
            // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
            auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
            C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}

typedef vector<ll> vl;
template<int M> vl convMod(const vl &a, const vl &b) {
    if (a.empty() || b.empty()) return {};
    vl res(sz(a) + sz(b) - 1);
    int B=32-__builtin_clz(sz(res)), n=1<<B, cut=int(sqrt(M));
    vector<C> L(n), R(n), outs(n), outl(n);
    rep(i,0,sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
    rep(i,0,sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
    fft(L), fft(R);
    rep(i,0,n) {
        int j = -i & (n - 1);
        outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
        outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
    }
    fft(outl), fft(outs);
    rep(i,0,sz(res)) {
        ll av = ll(real(outl[i])+.5), cv = ll(imag(outs[i])+.5);
        ll bv = ll(imag(outl[i])+.5) + ll(real(outs[i])+.5);
        res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
    }
    return res;
}

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}

struct Mod {
    ll x;
    Mod(): x(0) {}
    Mod(ll xx) : x(xx % mod) {}
    Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
    Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
    Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
    Mod operator/(Mod b) { return *this * invert(b); }
    Mod invert(Mod a) {
        ll x, y, g = euclid(a.x, mod, x, y);
        assert(g == 1); return Mod((x + mod) % mod);
    }
    Mod operator^(ll e) {
        if (!e) return Mod(1);
        Mod r = *this ^ (e / 2); r = r * r;
        return e&1 ? *this * r : r;
    }
    explicit operator ll() const { return x; }
};

typedef Mod num;
typedef vector<num> poly;
poly &operator+=(poly &a, const poly &b) {
    a.resize(max(sz(a), sz(b)));
    rep(i, 0, sz(b)) a[i] = a[i] + b[i];
    return a;
}
poly &operator-=(poly &a, const poly &b) {
    a.resize(max(sz(a), sz(b)));
    rep(i, 0, sz(b)) a[i] = a[i] - b[i];
    return a;
}

poly &operator*=(poly &a, const poly &b) {
    if (sz(a) + sz(b) < 100){
        poly res(sz(a) + sz(b) - 1);
        rep(i,0,sz(a)) rep(j,0,sz(b))
            res[i + j] = (res[i + j] + a[i] * b[j]);
        return (a = res);
    }
    auto res = convMod<mod>(vl(all(a)), vl(all(b)));
    // auto res = conv(vl(all(a)), vl(all(b)));
    return (a = poly(all(res)));
}
poly operator*(poly a, const num b) {
    poly c = a;
    for(auto& i: c) i = i * b;
    return c;
}
#define OP(o, oe) \
    poly operator o(poly a, poly b) { \
        poly c = a; \
        return c o##= b; \
    }
OP(*, *=) OP(+, +=) OP(-, -=);

poly modK(poly a, int k) { 
    return {a.begin(), a.begin() + min(k, sz(a))};
}
poly inverse(poly A) {
    int lim = sz(A);
    // assert(A[0]!=0);
    poly B = poly({num(1) / A[0]});
    while (sz(B) < lim)
        B = modK(B * (poly({num(2)}) - modK(A, 2*sz(B)) * B), 2 * sz(B));
    return modK(B, lim);
}

void solve() {
    cin >>n >>m >>q;
    rep(i,0,n) {
        cin >>a[i];
    }
    poly f(1,1);
    rep(i,0,n) {
        poly fa(a[i]+1,1);
        f = modK(f*fa,mxn*2+1);
    }
    poly dif(sz(f)+1);
    rep(i,0,sz(f)+1) {
        if(i<sz(f)) {
            dif[i] = f[i];
        }
        if(i && i-1<sz(f)) {
            dif[i] = dif[i] - f[i-1];
        }
        // cout <<dif[i].x <<"\n";
    }
    vector ans(mxn+5, poly(m+1,0));
    rep(i,1,mxn+5) {
        rep(j,0,m+1) {
            if(j<sz(dif)) {
                ans[i][j] = dif[j];
            }
            if(j>=i) {
                ans[i][j] = ans[i][j] + ans[i][j-i];
            }
        }
    }
    rep(i,0,q) {
        int k,x; cin >>k >>x; k--;
        if(m-x>=0) {
            cout <<ans[a[k]+1][m-x].x <<"\n";
        } else {
            cout <<"0\n";
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}