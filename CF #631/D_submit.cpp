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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int t;
ll n,m;

ll mod = 1000000007; // faster if const

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

vector<ll> berlekampMassey(vector<ll> s) {
	int n = sz(s), L = 0, m = 0;
	vector<ll> C(n), B(n), T;
	C[0] = B[0] = 1;

	ll b = 1;
	rep(i,0,n) { ++m;
		ll d = s[i] % mod;
		rep(j,1,L+1) d = (d + C[j] * s[i - j]) % mod;
		if (!d) continue;
		T = C; ll coef = d * modpow(b, mod-2) % mod;
		rep(j,m,n) C[j] = (C[j] - coef * B[j - m]) % mod;
		if (2 * L > i) continue;
		L = i + 1 - L; B = T; b = d; m = 0;
	}

	C.resize(L + 1); C.erase(C.begin());
	for (ll& x : C) x = (mod - x) % mod;
	return C;
}

typedef vector<ll> Poly;
ll linearRec(Poly S, Poly tr, ll k) {
	int n = sz(tr);

	auto combine = [&](Poly a, Poly b) {
		Poly res(n * 2 + 1);
		rep(i,0,n+1) rep(j,0,n+1)
			res[i + j] = (res[i + j] + a[i] * b[j]) % mod;
		for (int i = 2 * n; i > n; --i) rep(j,0,n)
			res[i - 1 - j] = (res[i - 1 - j] + res[i] * tr[j]) % mod;
		res.resize(n + 1);
		return res;
	};

	Poly pol(n + 1), e(pol);
	pol[0] = e[1] = 1;

	for (++k; k; k /= 2) {
		if (k % 2) pol = combine(pol, e);
		e = combine(e, e);
	}

	ll res = 0;
	rep(i,0,n) res = (res + pol[i + 1] * S[i]) % mod;
	return res;
}

void solve() {
    cin >>n >>m;
    vector<ll> awal = {1,3,5,11};
    vector<ll> rec = {666668329, 333326712, 0, 14901};
    mod = m;
    ll a2b = 14905;
    ll b5 = 1ll*(17-11*14901) - a2b;
    
    cout <<linearRec(awal, rec, n-1) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    // vector<ll> rec = {815202097, 897992055, 0, 152875647};
    // cout <<modpow(rec[0], mod-2) <<"\n";
    // cout <<modpow(rec[1], mod-2) <<"\n";
    // cout <<modpow(rec[3], mod-2) <<"\n";
    cin >>t;
    while(t--) {
        solve();
    }
}