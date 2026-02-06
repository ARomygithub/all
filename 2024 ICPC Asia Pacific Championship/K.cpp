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
typedef pair<pii,pii> pipi;
typedef pair<pii,int> piii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,q;
map<int,vector<pii>> qry1; map<int,vector<piii>> qry2;

struct Node {
	Node *l = 0, *r = 0;
	int val, y, c = 1;
    int ct,ch=-1, ctSub;
	Node(int val, int ct) : val(val), y(rand()), ct(ct), ctSub(ct) {}
	void recalc();
};

int cnt(Node* n) { return n ? n->c : 0; }
int cntSub(Node* n) {return n ? n->ctSub : 0;}
void Node::recalc() { 
    c = cnt(l) + cnt(r) + 1;
    ctSub = cntSub(l) + cntSub(r) + ct;
}

template<class F> void each(Node* n, F f) {
	if (n) { each(n->l, f); f(n->val); each(n->r, f); }
}

pair<Node*, Node*> split(Node* n, int k) {
	if (!n) return {};
	if (cnt(n->l) >= k) { // "n->val >= k" for lower_bound(k)
		auto pa = split(n->l, k);
		n->l = pa.second;
		n->recalc();
		return {pa.first, n};
	} else {
		auto pa = split(n->r, k - cnt(n->l) - 1); // and just "k"
		n->r = pa.first;
		n->recalc();
		return {n, pa.second};
	}
}

Node* merge(Node* l, Node* r) {
	if (!l) return r;
	if (!r) return l;
	if (l->y > r->y) {
		l->r = merge(l->r, r);
		l->recalc();
		return l;
	} else {
		r->l = merge(l, r->l);
		r->recalc();
		return r;
	}
}

// #include <bits/extc++.h> /** keep-include */
// using namespace __gnu_pbds;

// template<class T>
// using Tree = tree<T, null_type, less<T>, rb_tree_tag,
//     tree_order_statistics_node_update>;

int sub[mxn];
vector<int> adj[mxn];
// Tree<pii> oset;
vector<Node*> vtreaps;
Node* rtTreaps = 0;

void dfs1(int u, int p=-1) {
    sub[u] = 1;
    for(auto v: adj[u]) {
        if(v==p) continue;
        dfs1(v,u);
        sub[u] += sub[v];
    }
}

pipi getLoc(Node* nr, int id, int ord) {
    if(nr->ct > ord) {
        pipi ret = {{nr->val,nr->ch},{ord,id}};
        return ret;
    }
    if(nr->l && nr->l->ctSub>ord) {
        return getLoc(nr->l, id, ord);
    } else {
        return getLoc(nr->r, id, ord - cntSub(nr->l));
    }
}

void dfs2(int u, int p = -1) {
    if(qry1.count(u)) {
        vector<pii>& vtemp = qry1[u];
        for(auto [id, ord]: vtemp) {
            pipi loc = getLoc(rtTreaps, id, ord);
            qry2[loc.fi.fi].push_back({{loc.fi.se,loc.se.fi},loc.se.se});
        }
    }
    Node* nu = vtreaps.back();
    for(auto v: adj[u]) {
        if(v==p) continue;
        
        dfs2(v,u);

    }
}

void solve() {
    cin >>n >>q;
    int rt = -1;
    rep(i,0,n) {
        int pi; cin >>pi; pi--;
        if(pi!=-1) {
            adj[i].push_back(pi);
            adj[pi].push_back(i);
        } else {
            rt = i;
        }
    }
    rep(i,0,q) {
        int ki; cin >>ki; ki--;
        qry1[ki/n].push_back({i,(ki%n)});
    }
    dfs1(rt);
    // oset.insert({0,n});
    Node* nrt = new Node(rt, n);
    vtreaps.push_back(nrt);
    rtTreaps = nrt;
    dfs2(rt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}