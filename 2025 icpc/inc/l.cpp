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
ll n,k,m,l,t;

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
const long long base = 3;

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

class mint {
public:
	long long x;

public:
	mint() : x(0) {}
	mint(long long a) : x(a >= 0 ? a % mod : (a + 1) % mod + (mod - 1)) {}
	long long val() { return x; }

	// Operation (!!! number of pow operation can be 60 !!!)
	mint pow(long long b) {
		long long p = 1, q = x;
		for (int i = 0; i < 60; i++) {
			if ((b >> i) & 1) { p *= q; p %= mod; }
			q *= q; q %= mod;
		}
		return mint(p);
	}
	mint operator-() const { return mint(-x); }
	mint operator+(mint a) { return (x + a.x + mod) % mod; }
	mint operator-(mint a) { return (x - a.x + mod) % mod; }
	mint operator*(mint a) { return (x * a.x + mod) % mod; }
	mint operator/(mint a) { return (x * a.pow(mod - 2).val()) % mod; }
	mint& operator+=(mint a) { x = (x + a.x + mod) % mod; return (*this); }
	mint& operator-=(mint a) { x = (x - a.x + mod) % mod; return (*this); }
	mint& operator*=(mint a) { x = (x * a.x + mod) % mod; return (*this); }
	mint& operator/=(mint a) { x = (x * a.pow(mod - 2).val()) % mod; return (*this); }
};

// =========================================================================================================================================================
// === FFT Library
// =========================================================================================================================================================
vector<mint> ntt(vector<mint> vec, int typ) {
	mint root = (typ == 1 ? base : mint(1) / mint(base));
	int size_ = vec.size();
	vector<mint> dat(size_, 0);

	// Step A. Reverse Order
	for (int i = 0; i < size_; i++) {
		int r1 = 1, r2 = size_ / 2, cur = 0;
		while (r2 >= 1) {
			if ((i & r1) != 0) cur += r2;
			r1 <<= 1;
			r2 >>= 1;
		}
		dat[cur] = vec[i];
	}

	// Step B. Calculation
	for (int b = 2; b <= size_; b *= 2) {
		vector<mint> pows(b, 1);
		pows[1] = root.pow((mod - 1) / b);
		for (int i = 2; i < b; i++) pows[i] = pows[1] * pows[i - 1];

		// Main Part
		for (int stt = 0; stt < size_; stt += b) {
			for (int i = 0; i < b / 2; i++) {
				mint r1 = dat[stt + i] + pows[i + 0 * b / 2] * dat[stt + i + b / 2];
				mint r2 = dat[stt + i] + pows[i + 1 * b / 2] * dat[stt + i + b / 2];
				dat[stt + i + 0 * b / 2] = r1;
				dat[stt + i + 1 * b / 2] = r2;
			}
		}
	}

	// Step C. Finalize
	if (typ == 2) {
		mint mult = mint(1) / mint(size_);
		for (int i = 0; i < size_; i++) dat[i] = (dat[i] * mult);
	}
	return dat;
}

vector<mint> pwr(vector<mint> A, ll mi) {
	// Prepare
	int size_ = 1;
	while (size_ < A.size()) size_ *= 2;
	while (A.size() < size_) A.push_back(0);

	// First NTT
	vector<mint> r1 = ntt(A, 1);
	vector<mint> r3(size_, 0);
	for (int i = 0; i < size_; i++) r3[i] = r1[i].pow(mi);

	// Second NTT
	vector<mint> ret = ntt(r3, 2);
	return ret;
}

int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}

int generator (int p) {
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}


void solve() {
    cin >>n >>k >>m >>l;
    if(m==2) {
        int si; cin >>si;
        ll total = 1ll*si*l%m;
        if(total==k) {
            cout <<"1\n";
        } else {
            cout <<"0\n";
        }
        return;
    }
    vector<mint> poly(m-1,0);
    ll rt = generator(m);
    // debug() <<imie(rt);
    vi id(m,0);
    ll u = rt;
    int ct = 1;
    rep(i,1,m) {
        id[u] = ct%(m-1);
        u = u*rt%m;
        ct++;
    }
    // debug() <<imie(id);
    rep(i,0,n) {
        int si; cin >>si;
        poly[id[si]] += 1;
        // debug() <<imie(id[si]);
    }
    // debug() <<imie(poly);
    int ki = id[k];
    auto res = pwr(poly, l);
    ll ans = 0;
    for(int i=ki;i<sz(res);i+=(m-1)) {
        ans = (ans + res[i].x)%mod;
    }
    // rep(i,0,sz(res)) {
    //     debug() <<imie(i) <<imie(res[i].x);
    // }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}