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

const ll inf = 1e18;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
    ll mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, ll x) {
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

const int mxn=2e5;
int n,q;
ll a[mxn];

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>a[i];
    }
    Node st(0,n);
    set<int> non0;
    rep(i,0,n) {
        if(a[i]!=0) {
            non0.insert(i);
        }
        ll g = i>0?st.query(i-1,i):0ll;
        ll sq = floorl(sqrtl(1.0L*(a[i]+g)));
        st.set(i,i+1,sq);
    }
    while(q--) {
        int k;ll x; cin >>k >>x; k--;
        int non0a = n;
        if(sz(non0)) {
            non0a = *non0.begin();
        }
        if(a[k]==0 && x!=0) {
            non0.insert(k);
        } else if(a[k]!=0 && x==0) {
            non0.erase(k);
        }
        a[k] = x;
        int non0b = n;
        if(sz(non0)) {
            non0b = *non0.begin();
        } 
        rep(i,k,min(k+32,n)) {
            ll g = i>0?st.query(i-1,i):0ll;
            ll cur = floorl(sqrtl(1.0L*(g+a[i])));
            st.set(i,i+1,cur);
        }
        if(non0a<=k+32 && non0b>k+32) {
            st.set(k+32,non0b,0ll);
        } else if(non0a>k+32 && non0b<=k+32) {
            st.set(k+32,non0a,1ll);
        }
        cout <<st.query(n-1,n) <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}