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
int m,k;
int n[mxn];
const ll mod = (119 << 23) + 1, root = 62; // = 998244353

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
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
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = modpow(n, mod - 2);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
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
		assert(g == 1); 
        return Mod((x + mod) % mod);
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
	// auto res = convMod<mod>(vl(all(a)), vl(all(b)));
	auto res = conv(vl(all(a)), vl(all(b)));
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

poly modK(poly a, int k) { return {a.begin(), a.begin() + min(k, sz(a))}; }
poly inverse(poly A) {
	poly B = poly({num(1) / A[0]});
	while (sz(B) < sz(A)) {
		B = modK(B * (poly({num(2)}) - modK(A, 2*sz(B)) * B), 2 * sz(B));
    }
	return modK(B, sz(A));
}

void solve() {
    cin >>k >>m;
    int mx = 0;
    rep(i,0,m) {
        cin >>n[i];
        max_self(mx, n[i]);
    }
    if(k==1) {
        ll ans = 1;
        rep(i,0,m) {
            if(n[i]!=1) {
                ans = 0;
            }
        }
        cout <<ans <<"\n";
        return;
    }
    mx -= k;
    max_self(mx, k-1);
    poly p(mx+1,0);
    p[0] = 1;
    rep(i,1,k) {
        p[i] = mod-1;
    }
    auto ans = inverse(p);
    num anss = 1;
    rep(i,0,m) {
        anss = anss*ans[n[i] - k];
    }
    cout <<anss.x <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}