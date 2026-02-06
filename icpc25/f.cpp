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

const int mxn=2e3;
int n,m;
vi adj[mxn];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi deg(n);
    rep(i,0,n) {
        deg[i] = sz(adj[i]);
    }
    set<pii> s;
    rep(i,0,n) {
        s.insert({deg[i],i});
    }
    vi v1;
    int p = -1;
    while(sz(s)) {
        while(sz(s) && (*s.begin()).fi <= p) {
            auto u = (*s.begin()).se;
            s.erase(s.begin());
            for(auto v: adj[u]) {
                if(s.count({deg[v],v})) {
                    s.erase({deg[v],v});
                    deg[v]--;
                    s.insert({deg[v],v});
                }
            }
        }
        if(sz(s)) {
            p = (*s.begin()).fi;
            v1.clear();
            for(auto [d,si]: s) {
                v1.push_back(si);
            }
        }
    }
    int qm = (n+1+p)/(p+1) - 1;
    max_self(qm, 1);
    Dinic dnc(n*2+2);
    int st = n*2, tg = st+1;
    rep(i,0,n) {
        dnc.addEdge(st, i, 1);
        dnc.addEdge(i+n, tg, 1);
        for(auto j: adj[i]) {
            if(i<j) {
                dnc.addEdge(i,j+n,1);
            }
        }
    }
    int q = n - dnc.calc(st,tg);
    // assert(q >=qm);
    UF uf(n);
    rep(i,0,n) {
        for(auto& e: dnc.adj[i]) {
            if(e.flow()) {
                uf.join(i,e.to-n);
                break;
            }
        }
    }
    set<int> s2;
    rep(i,0,n) {
        s2.insert(uf.find(i));
    }
    vector<bool> vis(n,0), vis2(n,0);
    vi v2;
    rep(i,0,n) {
        int lead = uf.find(i);
        if(vis2[lead]) continue;
        if(vis[i]) continue;
        v2.push_back(i);
        vis2[lead] = 1;
        vis[i] = 1;
        for(auto j: adj[i]) {
            vis[j] = 1;
        }
    }
    assert(sz(s2)==sz(v2));
    // for(auto si: s2) {
    //     v2.push_back(si);
    // }
    // assert(sz(v2)==q);
    vi id(n);
    iota(all(id),0);
    // while(true) {
        // shuffle(all(id), rng);
        // sort(all(id), [&](int i, int j)-> bool {
        //     return sz(adj[i])<sz(adj[j]);
        // });
        // vector<bool> vis(n,0);
        // vi v2;
        // rep(i,0,sz(id)) {
        //     auto u = id[i];
        //     if(vis[u]) continue;
        //     for(auto v: adj[u]) {
        //         vis[v] = 1;
        //     }
        //     v2.push_back(u);
        // }
        if((p+1)*(sz(v2)+1) > n) {
            cout <<p <<" " <<sz(v2) <<"\n";
            cout <<sz(v1) <<" ";
            rep(i,0,sz(v1)) {
                cout <<v1[i]+1 <<" \n"[i==sz(v1)-1];
            }
            cout <<sz(v2) <<" ";
            rep(i,0,sz(v2)) {
                cout <<v2[i]+1 <<" \n"[i==sz(v2)-1];
            }
            return;
        }
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}