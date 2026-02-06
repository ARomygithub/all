#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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
int n;

using pli= pair<ll,int>;
const pli inf = {0,-1},setc={1e18,-1};
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
    pli mset = setc, val = inf;
    ll madd = 0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	pli query(int L, int R) {
		if (R <= lo || hi <= L) return inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, pli x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
            mset = x;
            val = x;
            madd = 0;
		} else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
    void add(int L, int R, ll x) {
        if(R<=lo || hi<=L) return;
        if(L <=lo && hi <= R) {
            if(mset!=setc) {
                mset.fi += x;
            } else {
                madd += x;
            }
            val.fi += x;
        } else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = max(l->val, r->val);
        }
    }
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != setc)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = setc;
        else if(madd) {
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd=0;
        }
	}
};

template <bool VALS_EDGES> struct HLD {
	int N, tim = 0;
	vector<vector<pii>> adj;
	vi par, siz, depth, rt, pos, wpar;
    vector<ll> valr;
	Node *tree;
	HLD(vector<vector<pii>> adj_)
		: N(sz(adj_)), adj(adj_), par(N, -1), wpar(N, 0), siz(N, 1), depth(N),
		  rt(N),pos(N),tree(new Node(0, N)), valr(N,0){ 
            dfsSz(0); dfsHld(0); 
        }
	void dfsSz(int v) {
		if (par[v] != -1) adj[v].erase(find(all(adj[v]), pii{wpar[v],par[v]}));
		for (auto& [w,u] : adj[v]) {
			par[u] = v, depth[u] = depth[v] + 1; wpar[u] = w; valr[u] = valr[v]+w;
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0].se]) swap(u, adj[v][0].se);
		}
	}
	void dfsHld(int v) {
		pos[v] = tim++;
		for (auto [w,u] : adj[v]) {
			rt[u] = (u == adj[v][0].se ? rt[v] : u);
			dfsHld(u);
		}
	}
	template <class B> void process(int u, int v, B op) {
		for (; rt[u] != rt[v]; v = par[rt[v]]) {
			if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
			op(pos[rt[v]], pos[v] + 1);
		}
		if (depth[u] > depth[v]) swap(u, v);
		op(pos[u] + VALS_EDGES, pos[v] + 1);
	}
	void modifyPath(int u, int v, pli val) {
		process(u, v, [&](int l, int r) { tree->set(l, r, val); });
	}
    void modifySubtree(int v, ll val) {
        tree->add(pos[v] + VALS_EDGES, pos[v]+siz[v], val);
    }
};

void solve() {
    cin >>n;
    vector<vector<pii>> adj(n);
    rep(i,1,n) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    HLD<false> hld(adj);
    rep(i,0,n) {
        hld.modifyPath(i, i, {hld.valr[i],i});
        // debug() <<imie(pii{hld.valr[i],i});
    }
    vector<ll> ans(n);
    vector<bool> vis(n,0);
    vis[0] = 1;
    rep(i,0,n) {
        auto [val,id] = hld.tree->query(0,n);
        // debug() <<imie(pii{val,id});
        ans[i] = val + (i>0?ans[i-1]:0);
        int u = id;
        while(!vis[u]) {
            vis[u] = 1;
            int p = hld.par[u];
            hld.modifySubtree(u, -hld.wpar[u]);
            // debug() <<imie(p) imie(-hld.wpar[u]);
            u = p;
        }
    }
    rep(i,0,n) {
        cout <<ans[i]*2 <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}