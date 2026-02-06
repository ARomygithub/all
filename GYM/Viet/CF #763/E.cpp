#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define all(x) begin(x), end(x)
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
int n,k;
int l[mxn+1],r[mxn+1],p[mxn+1], state[mxn+1];
string c;
vector<int> v;
bool ok[mxn+1];

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
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

template <bool VALS_EDGES> struct HLD {
	int N, tim = 0;
	vector<vi> adj;
	vi par, siz, depth, rt, pos;
	Node *tree;
	HLD(vector<vi> adj_)
		: N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
		  rt(N),pos(N),tree(new Node(0, N)){ dfsSz(0); dfsHld(0); }
	void dfsSz(int v) {
		if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
		for (int& u : adj[v]) {
			par[u] = v, depth[u] = depth[v] + 1;
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}
	void dfsHld(int v) {
		pos[v] = tim++;
		for (int u : adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
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
    void setVal(int u, int val) {
        process(u, u, [&](int l, int r) { tree->set(l, r, val); });
    }
	void modifyPath(int u, int v, int val) {
		process(u, v, [&](int l, int r) { tree->add(l, r, val); });
	}
	int queryPath(int u, int v) { // Modify depending on problem
		int res = -1e9;
		process(u, v, [&](int l, int r) {
				res = max(res, tree->query(l, r));
		});
		return res;
	}
	int querySubtree(int v) { // modifySubtree is similar
		return tree->query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
	}
};

void inorder(int u) {
    if(u==0) return;
    inorder(l[u]);
    v.push_back(u);
    inorder(r[u]);
}

void solve() {
    cin >>n >>k;
    cin >>c;
    rep(i,1,n+1) {
        cin >>l[i] >>r[i];
        p[l[i]] = i;
        p[r[i]] = i;
    }
    vector<vi> adj(n);
    rep(i,0,n) {
        if(l[i+1]>0) adj[i].push_back(l[i+1]-1);
        if(r[i+1]>0) adj[i].push_back(r[i+1]-1);
        if(p[i+1]>0) adj[i].push_back(p[i+1]-1);
    }
    HLD<false> hld(adj);
    inorder(1);
    per(i,n-1,-1) {
        if(i+1<n) {
            ok[v[i]] = c[v[i]-1]<c[v[i+1]-1];
            if(c[v[i]-1]==c[v[i+1]-1]) {
                ok[v[i]] = ok[v[i+1]];
            }
        } else {
            ok[v[i]] = 0;
        }
    }
    // cout <<"TES\n" <<flush;
    rep(i,0,n) {
        int u = v[i];
        if(state[u]!=0) continue;
        if(!ok[u]) {
            state[u] = -1;
            hld.setVal(u-1, hld.depth[u-1]);
            continue;
        }
        bool flag=1;
        vector<int> temp;
        // cout <<c[v[i]-1] <<"\n" <<flush;
        int q = hld.queryPath(u-1,0);
        max_self(q, -1);
        // cout <<q <<" " <<k <<" " <<hld.depth[u-1] <<"\n";
        if(q+k<hld.depth[u-1]) {
            // cout <<"jauh\n" <<flush;
            continue;
        }
        while(u!=0) {
            temp.push_back(u);
            // cout <<u <<"\n";
            u = p[u];
            if(state[u]==-1) {
                flag = 0;
                break;
            } else if(state[u]==1) {
                break;
            }
        }
        if(flag) {
            // cout <<"flag\n";
                // cout <<"flag2\n";
            for(int vv: temp) {
                state[vv] = 1;
                hld.setVal(vv-1, hld.depth[vv-1]);
            }
            k -=sz(temp);
        } else {
            // cout <<"!flag\n";
            for(int vv: temp) {
                state[vv] = -1;
                hld.setVal(vv-1, hld.depth[vv-1]);
            }
        }
    }
    rep(i,0,n) {
        if(state[v[i]]==1) {
            cout <<c[v[i]-1] <<c[v[i]-1];
        } else {
            cout <<c[v[i]-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}