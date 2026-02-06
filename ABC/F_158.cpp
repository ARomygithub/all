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

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

const int mxn=2e5;
const ll mod = 998244353;
int n;
pii xd[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>xd[i].fi >>xd[i].se;
    }
    sort(xd,xd+n);
    Tree st(n);
    per(i,n-1,-1) {
        int it = lower_bound(xd,xd+n,pii({xd[i].fi+xd[i].se,0})) - xd;
        it = max(it, st.query(i+1,it));
        st.update(i, it);
    }
    vector<ll> ans(n+1,1);
    per(i,n-1,-1) {
        int qry = st.query(i,i+1);
        ans[i] = (ans[i+1] + ans[qry])%mod;
    }
    cout <<ans[0] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}