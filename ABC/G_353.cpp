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

struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
    ll madd = 0, val = 0, maju=0, mundur=0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return l->query(L, R) + r->query(L, R);
	}
	void add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			madd += x;
			val += x*(hi-lo);
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = l->val + r->val;
		}
	}
    void addR(int L, int R, ll x) {
        if(R <= lo || hi <=L) return;
        if(L <=lo && hi<= R) {
            ll awl = x*(lo-L);
            madd += awl;
            maju += x;
            val += awl*(hi-lo);
            val += x*(hi-lo-1)*(hi-lo)/2;
        } else {
            push(), l->addR(L, R, x), r->addR(L, R, x);
            val = l->val + r->val;
        }
    }
    void addL(int L, int R, ll x) {
        if(R <= lo || hi <=L) return;
        if(L <=lo && hi<= R) {
            ll awl = x*(R-hi);
            madd += awl;
            mundur += x;
            val += awl*(hi-lo);
            val += x*(hi-lo-1)*(hi-lo)/2;
        } else {
            push(), l->addL(L, R, x), r->addL(L, R, x);
            val = l->val + r->val;
        }
    }    
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (madd!=0)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
        if(maju!=0) {
            l->addR(lo,hi,maju), r->addR(lo,hi,maju), maju=0;
        }
        if(mundur!=0) {
            l->addL(lo,hi,mundur), r->addL(lo,hi,mundur), mundur=0;
        }
	}
};

const int mxn=2e5;
ll n,c, m;
pll tp[mxn];

void solve() {
    cin >>n >>c;
    cin >>m;
    rep(i,0,m) {
        cin >>tp[i].fi >>tp[i].se;
        tp[i].fi--;
    }
    Node st(0,n);
    vector<ll> ans(n,0);
    per(i,m-1,-1) {
        ll ct = tp[i].se/c;
        int le = max(tp[i].fi-ct,0ll);
        int ri = min(tp[i].fi+ct,n-1);
        st.add(le,ri+1, tp[i].se);
        st.addL(le, tp[i].fi+1, c*-1);
        st.addR(tp[i].fi, ri+1, c*-1);
        rep(j,0,n) {
            if(j==tp[i].fi) continue;
            max_self(ans[j], ans[tp[i].fi] + tp[i].se - c*abs(j-tp[i].fi));
        }
        ans[tp[i].fi] += tp[i].se;
        rep(j,0,n) {
            cout <<ans[j] <<" ";
            // cout <<st.query(j,j+1) <<" ";
        }
        cout <<endl;
    }
    cout <<st.query(0,1) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}