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

const ll inf = -1e18;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
    ll mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = min(l->val, r->val);
		}
		else val = v[lo];
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return min(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = min(l->val, r->val);
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
			val = min(l->val, r->val);
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

typedef pair<int,pii> ipii;
const int mxn=5e5;
int n,q;
vector<pii> adj[mxn];
vector<ipii> qry[mxn];
ll d[mxn];
int s[mxn],e[mxn];

void solve() {
    cin >>n >>q;
    rep(i,1,n) {
        int p,w; cin >>p >>w; p--;
        adj[p].push_back({w,i});
        adj[i].push_back({w,p});
    }
    vector<ll> ans(q);
    rep(i,0,q) {
        int v,l,r; cin >>v >>l >>r; v--,l--;
        qry[v].push_back({i,{l,r}});
    }
    Node st(0,n);
    function<void(int,int)> dfs1;
    dfs1 = [&](int u, int p) -> void {
        s[u] = u, e[u] = u;
        for(auto [w,v]: adj[u]) {
            if(v==p) continue;
            d[v] = d[u]+w;
            dfs1(v,u);
            max_self(e[u], e[v]);
        }
        if(sz(adj[u])==1) {
            st.set(u, u+1, d[u]);
        }
    };
    dfs1(0,-1);
    function<void(int,int)> dfs2;
    dfs2 = [&](int u, int p) -> void {
        ll dif = d[u] - (p==-1?0ll:d[p]);
        st.add(s[u],e[u]+1, dif*-2ll);
        if(sz(qry[u])) {
            for(auto [id,lr]: qry[u]) {
                auto [l,r] = lr;
                ans[id] = st.query(l,r);
                ans[id] += d[u];
            }
        }
        for(auto [w,v]: adj[u]) {
            if(v==p) continue;
            dfs2(v,u);
        }
        st.add(s[u],e[u]+1, dif*2ll);
    };
    dfs2(0,-1);
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}