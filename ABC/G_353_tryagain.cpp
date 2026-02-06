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

const int mxn=2e5;
ll n,c, m;
pll tp[mxn];

struct Tree {
	typedef ll T;
	static constexpr T unit = LLONG_MIN;
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

void solve() {
    cin >>n >>c;
    cin >>m;
    rep(i,0,m) {
        cin >>tp[i].fi >>tp[i].se;
        tp[i].fi--;
    }
    Tree stm(n), sta(n);
    stm.update(0, 0ll);
    sta.update(0, 0ll);
    rep(i,0,m) {
        int j = tp[i].fi;
        ll qrya = sta.query(0,j+1);
        // assert(qrya!=LLONG_MIN);
        ll temp = qrya - c*j;
        ll qrym = stm.query(j, n);
        if(qrym!=LLONG_MIN) {
            max_self(temp, qrym + c*j);
        }
        temp += tp[i].se;
        sta.update(j, temp+c*j);
        stm.update(j, temp-c*j);
    }
    ll ans = 0;
    rep(i,0,n) {
        ll temp = sta.query(i,i+1);
        if(temp!=LLONG_MIN) {
            max_self(ans, sta.query(i,i+1)-c*i);
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}