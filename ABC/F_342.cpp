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
int n,l,d;

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf;
    double madd = 0.0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vector<double>& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	double query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, double x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, double x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

void solve() {
    cin >>n >>l >>d;
    vector<double> p(l+d);
    Node stp(p, 0, l+d);
    stp.set(0,1, 1.0);
    rep(i,0,l) {
        double qry = stp.query(i,i+1);
        stp.add(i+1,i+d+1, qry/d);
        stp.set(i,i+1,0.0);
    }
    vector<double> q(n+1);
    q[0] = 0.0;
    rep(i,1,n+1) {
        double temp = i-1<=l+d-1?stp.query(i-1,i):0.0;
        q[i] = q[i-1]+temp;
    }
    // rep(i,n-30,n+1) {
    //     cout <<fixed <<setprecision(8) <<q[i] <<"\n";
    // }
    double keluar = 0.0;
    rep(i,n+1,l+d) {
        keluar += stp.query(i,i+1);
    }
    vector<double> r(n+1);
    r[n] = q[n]+keluar;
    double sum = r[n];
    int rr = n;
    per(i,n-1,-1) {
        if(rr>i+d) {
            sum -=r[rr];
            rr--;
        }
        r[i] = max(q[i]+keluar, sum/d);
        sum += r[i];
    }
    cout <<fixed <<setprecision(8) <<r[0] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}