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
int n;

const ll mod = 1000000007; // faster if const

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

void solve() {
    vector<ll> v{1, 10, 40, 105, 219, 396, 650, 995};
    // vector<ll> v{0, 1, 7, 31, 105, 295, 721, 1582, 3186, 5985, 10615, 17941, 29107, 45591, 69265};
    auto ret = berlekampMassey(v);
    debug() <<imie(ret);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}