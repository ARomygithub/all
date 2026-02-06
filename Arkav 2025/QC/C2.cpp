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

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

struct Mod {
	ll x;
    Mod(): x(0) {}
	Mod(ll xx) : x(xx%mod) {}
	Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
	Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
	Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
	Mod operator/(Mod b) { return *this * invert(b); }
	Mod invert(Mod a) {
		ll x, y, g = euclid(a.x, mod, x, y);
		// assert(g == 1);
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
	while (sz(B) < sz(A))
		B = modK(B * (poly({num(2)}) - modK(A, 2*sz(B)) * B), 2 * sz(B));
	return modK(B, sz(A));
}

poly deriv(poly a) {
	if (a.empty()) return {};
	poly b(sz(a) - 1);
	rep(i, 1, sz(a)) b[i - 1] = a[i] * num(i);
	return b;
}
poly integr(poly a) {
	if (a.empty()) return {0};
	poly b(sz(a) + 1);
	b[1] = num(1);
	rep(i, 2, sz(b)) b[i] = b[mod%i]*Mod(-mod/i+mod);
	rep(i, 1 ,sz(b)) b[i] = a[i-1] * b[i];
	return b;
}

poly log(poly a) {
	return modK(integr(deriv(a) * inverse(a)), sz(a));
}
poly exp(poly a) {
	poly b(1, num(1));
	if (a.empty())
		return b;
	while (sz(b) < sz(a)) {
		b.resize(sz(b) * 2);
		b *= (poly({num(1)}) + modK(a, sz(b)) - log(b));
		b.resize(sz(b) / 2 + 1);
	}
	return modK(b, sz(a));
}

poly shift(poly a, ll x) {
	poly res(sz(a));
	rep(i,0,sz(a)) {
		if(i-x>=0 && i-x<sz(a)) {
			res[i] = a[i-x];
		}
	}
	return res;
}

poly pow(poly a, ll m) {
	if(m==0) {
		fill(all(a), 0);
		a[0] = 1;
		return a;
	}
	int p = 0, n = sz(a);
	while (p < sz(a) && a[p].x == 0)
		++p;
	if(p==n) return a;
	if (p >= (n + m-1)/m) return poly(sz(a));
	num j = a[p];
	a = {a.begin() + p, a.end()};
	a = a * (num(1) / j);
	a.resize(n);
	auto res =  exp(log(a) * num(m)) * (j ^ m);
    cout <<"sz " <<sz(res) <<endl; 
	// res.insert(res.begin(), p*m, 0);
	res = shift(res, p*m);
	return {res.begin(), res.begin()+n};
}

ll inv(ll b) {
    return modpow(b, mod-2);
}

void solve() {
    cin >>n >>m >>k;
    int k2 = 1<<k;
    poly v(k2, num(0));
    ll sm = 0;
    rep(i,1,n+1) {
        int ai; cin >>ai;
        v[i%k2] = v[i%k2] + num(ai);
        sm += ai;
    }
    sm %= mod;
    ll iv = inv(modpow(sm,m));
    auto res = pow(v,m);
    rep(i,1,k2+1) {
        ll cur = res[i%k2].x;
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