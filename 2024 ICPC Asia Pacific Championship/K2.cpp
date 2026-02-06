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

// store info val /-> ch
// ct. ctSub = ctPref
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

// split val<k dan val >=k
pair<Node*, Node*> split(Node* n, int k) {
	if (!n) return {};
	if (n->val >= k) { // "n->val >= k" for lower_bound(k)
		auto pa = split(n->l, k);
		n->l = pa.second;
		n->recalc();
		return {pa.first, n};
	} else {
		auto pa = split(n->r, k); // and just "k"
		n->r = pa.first;
		n->recalc();
		return {n, pa.second};
	}
}

// merge l,r given k e l < k e r
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

// insert node dgn val, y, ct baru
Node* insert(Node* nu, Node* nv) {
    if(!nu) {
        return nv;
    } else if(nv->y > nu->y) {
        auto ret = split(nu, nv->val);
        nv->l = ret.fi;
        nv->r = ret.se;
        nv->recalc();
        return nv;
    } else {
        if(nu->val <= nv->val) {
            nu->r = insert(nu->r, nv);
        } else {
            nu->l = insert(nu->l, nv);
        }
        nu->recalc();
        return nu;
    }
}

// delete node
Node* deleteN(Node* nu, int k) {
    if(nu->val == k) {
        Node* ret = merge(nu->l, nu->r);
        delete nu;
        return ret;
    } 
    if(nu->val < k) {
        nu->r = deleteN(nu->r, k);
    } else {
        nu->l = deleteN(nu->l, k);
    }
    nu->recalc();
    return nu;
}

// point update ct dan ctSub di atasnya
void point_update(Node* nu, int k, int ct_new) {
    if(nu->val == k) {
        nu->ct = ct_new;
        nu->recalc();
        return;
    }
    if(nu->val > k) {
        point_update(nu->l, k, ct_new);
    } else {
        point_update(nu->r, k, ct_new);
    }
    nu->recalc();
}

Node* unite(Node* l, Node* r) {
    if(!l || !r) return l ? l: r;
    if(l->y < r->y) swap(l,r);
    auto ret = split(r, l->val);
    l->l = unite(l->l, ret.fi);
    l->r = unite(l->r, ret.se);
    l->recalc();
    return l;
}

int sub[mxn];
vector<int> adj[mxn];
vector<Node*> vtreaps;
Node* rtTreaps = 0;
ll ans[mxn];

void dfs1(int u, int p=-1) {
    sub[u] = 1;
    for(auto v: adj[u]) {
        if(v==p) continue;
        dfs1(v,u);
        sub[u] += sub[v];
    }
}

pipi getLoc(Node* nr, int id, int ord) {
    debug() <<imie(nr->val) <<imie(nr->ctSub);
    if(nr->l) {
        debug() <<imie(nr->l->val) <<imie(nr->l->ctSub);
    }
    if(nr->r) {
        debug() <<imie(nr->r->val);
    }
    if(nr->l && nr->l->ctSub>ord) {
        debug() <<imie(nr->l->val);
        return getLoc(nr->l, id, ord);
    } else if(cntSub(nr->l) + nr->ct > ord) {
        pipi ret = {{nr->val,nr->ch},{ord-cntSub(nr->l),id}};
        return ret;        
    } else {
        debug() <<imie(nr->r->val);
        return getLoc(nr->r, id, ord - cntSub(nr->l)-nr->ct);
    }
}

void dfs2(int u, int p = -1) {
    cout <<u <<"\n" <<flush;
    debug() <<imie(rtTreaps->val) <<imie(rtTreaps->ctSub);
    if(qry1.count(u)) {
        cout <<"loc " <<u <<endl;
        vector<pii>& vtemp = qry1[u];
        for(auto [id, ord]: vtemp) {
            pipi loc = getLoc(rtTreaps, id, ord);
            qry2[loc.fi.fi].push_back({{loc.fi.se,loc.se.fi},loc.se.se});
        }
        cout <<"finish loc " <<u <<endl;
    }
    Node* nu = vtreaps.back();
    for(auto v: adj[u]) {
        if(v==p) continue;
        int ct_new = nu->ct - sub[v];
        point_update(rtTreaps, u, ct_new);
        nu->ch = v;
        Node* nv = new Node(v, sub[v]);
        rtTreaps = insert(rtTreaps, nv);
        vtreaps.push_back(nv);
        dfs2(v,u);
        rtTreaps = deleteN(rtTreaps, v);
        vtreaps.pop_back();
        nu->ch = -1;
        ct_new += sub[v];
        point_update(rtTreaps, u, ct_new);
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
        ans[i] += (ki/n)*n*n;
    }
    dfs1(rt);
    Node* nrt = new Node(rt, n);
    vtreaps.push_back(nrt);
    rtTreaps = nrt;
    cout <<"dfs2 \n" <<flush;
    dfs2(rt);
    // rep(i,0,n) {
    //     if(qry2.count(i)) {
    //         for(auto [chord,id]: qry2[i]) {
    //             auto [ch, ord] = chord;
    //             cout <<i <<" " <<ch <<" " <<ord <<" " <<id <<"\n";
    //         }
    //     }
    // }
    dfsTreap(rt);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}