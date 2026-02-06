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

const int mxn=2e5;
int n,k;
pii a[mxn],s;

struct Tree {
	typedef double T;
	static constexpr T unit = DBL_MAX;
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

double dist(pii i, pii j) {
    return sqrt(1ll*(i.fi-j.fi)*(i.fi-j.fi) + 1ll*(i.se-j.se)*(i.se-j.se));
}

void solve() {
    cin >>n >>k;
    cin >>s.fi >>s.se;
    rep(i,0,n) {
        cin >>a[i].fi >>a[i].se;
    }
    double sum=0.0;
    rep(i,1,n) {
        sum +=dist(a[i],a[i-1]);
        // cout <<fixed <<setprecision(8) <<dist(a[i],a[i-1]) <<"\n";
    }
    if(k==1) {
        double ans = 0;
        rep(i,0,n) {
            ans +=dist(s,a[i])*2;
        }
        cout <<fixed <<setprecision(8) <<ans <<"\n";
        return;
    }
    // cout <<sum <<"\n";
    Tree st(n);
    rep(i,0,n) {
        if(i==0) {
            double temp = dist(s,a[i])*2;
            if(i+1<n) {
                temp -=dist(a[i],a[i+1]);
                temp +=dist(s,a[i+1]);
            }
            st.update(i,temp);
            // cout <<temp <<"\n";
            continue;
        }
        double qry = st.query(max(0,i-k), i);
        if(i-k<0) {
            min_self(qry, dist(s,a[0]));
        }
        double sti = qry+dist(s,a[i]);
        if(i+1<n) {
            sti -=dist(a[i],a[i+1]);
            sti +=dist(s,a[i+1]);
        }
        st.update(i,sti);
        // cout <<sti <<"\n";
    }
    cout <<fixed <<setprecision(8) <<st.query(n-1,n)+sum <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}