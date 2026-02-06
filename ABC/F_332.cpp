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
const ll mod=998244353;
int n,m;

const int inf = 0;
const pll unit = {0,1};
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = 0;
    pll mop = unit;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = (l->val + r->val)%mod;
		}
		else val = v[lo]%mod;
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return (l->query(L, R) + r->query(L, R))%mod;
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
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
	void op(int L, int R, pll x) {
        if(R<= lo || hi <= L) return;
        if(L <= lo && hi <= R) {
            val = (1ll*x.fi + 1ll*val*x.se%mod)%mod;
            mop.se = mop.se*x.se%mod;
            mop.fi = (mop.fi*x.se%mod + x.fi)%mod;
        } else {
            push(), l->op(L, R, x), r->op(L, R, x);
            val = (l->val + r->val)%mod;
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
        else if (mop != unit) {
            l->op(lo,hi,mop), r->op(lo,hi,mop), mop = unit;
        }
	}
};

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

ll inv(ll a) {
    return fastexpo(a, mod-2);
}

void solve() {
    cin >>n >>m;
    vector<int> a(n);
    rep(i,0,n) {
        cin >>a[i];
    }
    Node st(a, 0, n); 
    while(m--) {
        int l,r,x; cin >>l >>r >>x; l--,r--;
        ll add = 1ll*x*inv(r-l+1)%mod;
        ll mul = 1ll*(r-l)*inv(r-l+1)%mod;
        st.op(l, r+1, {add,mul});
    }
    rep(i,0,n) {
        cout <<st.query(i,i+1) <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}