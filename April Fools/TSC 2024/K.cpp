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
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a+ b; } // (any associative fn)
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
int n,q;
ll a[mxn];

void solve() {
    cin >>n >>q;
    Tree st(n);
    while(q--) {
        int awl; cin >>awl;
        int qt; cin >>qt;
        if(qt==1) {
            int x,w; cin >>w;
            x = awl; x--;
            st.update(x,a[x]+w);
            a[x] = a[x]+w;
        } else if(qt==2) {
            int x,w; cin >>w;
            x = awl; x--;
            st.update(x,w);
            a[x] = w;
        } else {
            int l,r; cin >>r;
            l = awl; l--;
            // rep(i,l,r) {
            //     cout <<st.query(i,i+1) <<" \n"[i==r-1];
            // }
            cout <<st.query(l,r) <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}