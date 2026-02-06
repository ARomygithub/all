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

const int mxn=100;
const ll mod=1e9+7;
int n;
// O(n^2) sol: https://codeforces.com/contest/917/submission/172893344

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
    int n = sz(a), L = 31- __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);
    for (static int k=2;k<n; k*=2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L)/k);
        rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2]*x : R[i/2];
    }
    vi rev(n);
    rep(i,0,n) rev[i] = (rev[i/2] | (i&1) << L)/2;
    rep(i,0,n) if(i<rev[i]) swap(a[i], a[rev[i]]);
    for(int k=1;k<n;k*=2) {
        for(int i=0;i<n;i+=2*k) rep(j,0,k) {
            C z = rt[j+k] * a[i+j+k];
            a[i+j+k] = a[i+j]-z;
            a[i+j] += z;
        }
    }
}

typedef vector<ll> vl;
template<int M> vl convMod(const vl& a, const vl& b) {
    if(a.empty() || b.empty()) return {};
    vl res(sz(a)+sz(b)-1);
    int B = 32-__builtin_clz(sz(res)), n = 1<<B, cut = int(sqrt(M));
    vector<C> L(n), R(n), outs(n), outl(n);
    rep(i,0,sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
    rep(i,0,sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
    fft(L), fft(R);
    rep(i,0,n) {
        int j = -i & (n-1);
        outl[j] = (L[i] + conj(L[j])) * R[i]/ (2.0 * n);
        outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0*n)/ 1i;
    }
    fft(outl), fft(outs);
    rep(i,0,sz(res)) {
        ll av = ll(real(outl[i])+.5), cv = ll(imag(outs[i]) + .5);
        ll bv = ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5);
        res[i] = ((av%M * cut + bv) %M * cut + cv)%M;
    }
    return res;
}

ll euclid(ll a, ll b, ll &x, ll &y) {
    if(!b) return x=1, y=0, a;
    ll d = euclid(b, a%b, y, x);
    return y -= a/b * x, d;
}

struct Mod {
    ll x; 
    Mod() : x(0) {}
    Mod(ll xx): x(xx%mod) {}
    Mod operator+(Mod b) { return Mod((x+b.x)%mod); }
    Mod operator-(Mod b) { return Mod((x-b.x + mod)%mod); }
    Mod operator*(Mod b) { return Mod((x*b.x)%mod); }
    Mod operator/(Mod b) { return *this * invert(b); }
    Mod invert(Mod a) {
        ll x,y,g = euclid(a.x, mod, x, y);
        assert(g==1); return Mod((x+mod)%mod);
    }
    Mod operator^(ll e) {
        if(!e) return Mod(1);
        Mod r = *this ^ (e/2); r = r*r;
        return e&1 ? *this * r: r;
    }
    explicit operator ll() const {
        return x;
    }
};

typedef Mod num;
typedef vector<num> poly;
poly &operator+=(poly &a, const poly &b) {
    a.resize(max(sz(a), sz(b)));
    rep(i,0,sz(b)) a[i] = a[i] + b[i];
    return a;
}
poly &operator-=(poly &a, const poly &b) {
    a.resize(max(sz(a),sz(b)));
    rep(i,0,sz(b)) a[i] = a[i] - b[i];
    return a;
}
poly &operator*=(poly &a, const poly& b) {
    if(sz(a) + sz(b) <100) {
        poly res(sz(a) + sz(b) -1);
        rep(i,0,sz(a)) rep(j,0,sz(b))
            res[i+j] = (res[i+j] + a[i]*b[j]);
        return (a=res);
    }
    auto res = convMod<mod>(vl(all(a)), vl(all(b)));
    return (a = poly(all(res)));
}
poly operator*(poly a, const num b) {
    poly c = a;
    for(auto& i : c) i = i*b;
    return c;
}
#define OP(o, oe) \
    poly operator o(poly a, poly b) { \
        poly c = a; \
        return c o##= b; \
    }
OP(*, *=) OP(+, +=) OP(-, -=);

poly modK(poly a, int k) { return {a.begin(), a.begin() + min(k, sz(a))}; };
poly inverse(poly A) {
    poly B = poly({num(1) / A[0]});
    while(sz(B)<sz(A))
        B = modK(B * (poly({num(2)}) - modK(A, 2*sz(B)) * B), 2*sz(B));
    return modK(B, sz(A));
}
poly &operator/=(poly &a, poly b) {
    if(sz(a) < sz(b))
        return a = {};
    int s = sz(a) - sz(b) + 1;
    reverse(all(a)), reverse(all(b));
    a.resize(s), b.resize(s);
    a = a * inverse(b);
    a.resize(s), reverse(all(a));
    return a;
}
OP(/, /=)
poly &operator%=(poly &a, poly &b) {
    if(sz(a) < sz(b))
        return a;
    poly c = (a/b) * b;
    a.resize(sz(b)-1);
    rep(i,0,sz(a)) a[i] = a[i] - c[i];
    return a;
}
OP(%, %=)

poly deriv(poly a) {
    if(a.empty()) return {};
    poly b(sz(a) -1);
    rep(i,1,sz(a)) b[i-1] = a[i]*num(i);
    return b;
}
poly integr(poly a) {
    if(a.empty()) return {0};
    poly b(sz(a)+1);
    b[1] = num(1);
    rep(i,2,sz(b)) b[i] = b[mod%i]*Mod(-mod/i + mod);
    rep(i,1,sz(b)) b[i] = a[i-1]*b[i];
    return b;
}

vector<num> eval(const poly& a, const vector<num> &x) {
    int n = sz(x);
    if(!n) return {};
    vector<poly> up(2*n);
    rep(i,0,n) up[i+n] = poly({num(0)-x[i], 1});
    for(int i = n-1; i>0; i--)
        up[i] = up[2*i]*up[2*i+1];
    vector<poly> down(2*n);
    down[1] = a%up[1];
    rep(i,2,2*n) down[i] = down[i/2]%up[i];
    vector<num> y(n);
    rep(i,0,n) y[i] = down[i+n][0];
    return y;
}

poly interp(vector<num> x, vector<num> y) {
    int n = sz(x);
    vector<poly> up(n*2);
    rep(i,0,n) up[i+n] = poly({num(0)-x[i], num(1)});
    per(i,n-1,0) up[i] = up[2*i]*up[2*i+1];
    vector<num> a = eval(deriv(up[1]), x);
    vector<poly> down(2*n);
    rep(i,0,n) down[i+n] =poly({y[i]*num(1)/a[i]});
    per(i,n-1,0) down[i] = down[i*2] * up[i*2+1] + down[i*2+1]*up[i*2];
    return down[1];
}

ll det(vector<vector<ll>>& a) {
    int n = sz(a); ll ans = 1;
    rep(i,0,n) {
        rep(j,i+1,n) {
            while(a[j][i] != 0) {
                ll t = a[i][i] / a[j][i];
                if(t) rep(k,i,n)
                    a[i][k] = (a[i][k] - a[j][k] * t)%mod;
                swap(a[i], a[j]);
                ans *= -1; 
            }
        }
        ans = ans * a[i][i] %mod;
        if(!ans) return 0;
    }
    return (ans + mod)%mod;
}

void solve() {
    cin >>n;
    vector<pii> ed;
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        ed.push_back({u,v});
    }
    vector<num> px,py;
    rep(x,1,n+1) {
        vector mat(n, vector<ll>(n,0));
        rep(i,0,n) {
            rep(j,0,n) {
                if(i==j) {
                    mat[i][j] = (n-1)%mod;
                } else {
                    mat[i][j] = mod-1;
                }
            }
        }
        for(auto [u,v]: ed) {
            mat[u][v] = (mat[u][v] - (x-1) + mod)%mod;
            mat[v][u] = (mat[v][u] - (x-1) + mod)%mod;
            mat[u][u] = (mat[u][u] + (x-1))%mod;
            mat[v][v] = (mat[v][v] + (x-1))%mod; 
        }
        mat.pop_back();
        rep(i,0,sz(mat)) {
            mat[i].pop_back();
        }
        px.push_back(x);
        py.push_back(det(mat));
    }
    auto ans = interp(px, py);
    rep(i,0,n) {
        cout <<ans[i].x <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}