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
int n,t;
ll a[mxn];

struct Tree {
	typedef ll T;
	static constexpr T unit = LLONG_MAX;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
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
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,1,n) {
        a[i] +=a[i-1];
    }
    ll l=0, r=a[n-1];
    ll ans = -1;
    while(l<=r) {
        ll mid = (l+r)/2;
        Tree dp(n+1);
        dp.update(0, a[0]);
        ll midtemp = -1;
        rep(i,1,n+1) {
            int li = -1, ri = i-1;
            int bwh= i-1;
            while(li<=ri) {
                int midi = (li+ri)/2;
                ll temp = a[i-1] -(midi>=0?a[midi]:0ll);
                if(temp<=mid) {
                    bwh = midi;
                    ri = midi-1;
                } else {
                    li = midi+1;
                }
            }
            ll qry;
            if(bwh<0) {
                qry = 0;
            } else {
                qry = dp.query(bwh,i);
            }
            if(i<n) {
                qry += (a[i]-a[i-1]);
            } else {
                midtemp = qry;
            }
            dp.update(i, qry);
        }
        if(midtemp <= mid) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}