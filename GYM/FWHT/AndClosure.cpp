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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
const ll mod=998244353;
int n;

ll fastexpo(ll ai, ll bi) {
    ll ret=1;
    while(bi) {
        if(bi&1) ret =ret*ai%mod;
        ai = ai*ai%mod;
        bi >>=1;
    }
    return ret;
}

void FST(vi& a, bool inv) {
	for (int n = sz(a), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
			int &u = a[j], &v = a[j + step]; tie(u, v) =
				inv ? pii(v - u, u) : pii(v, u + v); // AND
				// inv ? pii(v, u - v) : pii(u + v, u); // OR /// include-line
				// pii(u + v, u - v);                   // XOR /// include-line
            u %=mod; v%=mod;
            u = (u+mod)%mod; v = (v+mod)%mod;
		}
	}
	// if (inv) for (int& x : a) x /= sz(a); // XOR only /// include-line
}
vi conv(vi a, vi b) {
	FST(a, 0); FST(b, 0);
	rep(i,0,sz(a)) a[i] *= b[i];
	FST(a, 1); return a;
}
vi poww(vi a, int nn) {
    FST(a,0);
    rep(i,0,sz(a)) {
        a[i] = fastexpo(a[i],nn);
    }
    FST(a,1); return a;
}

void solve() {
    cin >>n;
    vi a(1<<20,0);
    rep(i,0,n) {
        int ai; cin >>ai;
        a[ai] = 1;
    }
    a[0] = 1;
    vi res = poww(a,n);
    int ans=0;
    rep(i,0,1<<20) {
        ans +=(res[i]!=0);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}