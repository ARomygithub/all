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
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,t;
int c[mxn],a[mxn],p[mxn];

const ll inf = 1e15;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
    ll mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return l->query(L, R) + r->query(L, R);
	}
	void set(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = x, val = x*(hi-lo), madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
            val = (l->val + r->val);
        }
	}
	void add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x*(hi-lo);
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
            val = (l->val + r->val);
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
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>c[i];
    }
    rep(i,0,n) {
        cin >>p[i]; p[i]--;
    }
    vector<pii> v;
    rep(i,0,n) {
        v.push_back({a[i],i});
    }
    sort(all(v),greater<pii>());
    vector<pii> lr(n);
    set<int> s;
    for(int i =0;i<n;) {
        int j = i+1;
        while(j<n && v[j].fi==v[i].fi) {
            j++;
        }
        rep(k,i,j) {
            auto [ai,u] = v[k];
            auto it = s.lower_bound(u);
            if(it!=s.begin()) {
                it--;
                lr[u].fi = *it;
                it++;
            } else {
                lr[u].fi = -1;
            }
            if(it!=s.end()) {
                lr[u].se = *it;
            } else {
                lr[u].se = n;
            }
        }
        rep(k,i,j) {
            auto u = v[k].se;
            s.insert(u);
        }
        i = j;
    }
    int imx = v[0].se;
    vector<pii> v2;
    rep(i,0,n) {
        v2.push_back({c[i],i});
    }
    sort(all(v2));
    Node st(0,n);
    per(i,sz(v2)-1,-1) {
        auto u = v2[i].se;
        auto [l,r] = lr[u];
        st.set(l+1,r,v2[i].fi);
    }
    vector<ll> ans(n+1);
    ans[0] = st.query(0,n) - st.query(imx,imx+1);
    rep(i,1,n+1) {
        auto [l,r] = lr[p[i-1]];
        st.set(l+1,r,0);
        ans[i] = st.query(0,n) - st.query(imx,imx+1);
    }
    rep(i,0,n+1) {
        cout <<ans[i] <<" \n"[i==n];
    }
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