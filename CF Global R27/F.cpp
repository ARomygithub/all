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
int n,x,t;
int a[mxn];
vi adj[mxn];

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

int d[mxn];
void dfs(int u, int p=-1) {
    for(int v: adj[u]) {
        if(v==p) continue;
        d[v] = d[u]+1;
        dfs(v,u);
    }
}

void solve() {
    cin >>n >>x; x--;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    d[x] = 0;
    dfs(x);
    ll ans = -1;
    ll l = 0, r = 4e15;
    const int inf = 4e12;
    ll sa = 0;
    rep(i,0,n) {
        sa += a[i];
    }
    while(l<=r) {
        ll mid = (l+r)/2;
        Dinic dnc(n+4);
        int st=n, tg=n+1, st2=n+2, tg2=st2+1;
        rep(i,0,n) {
            for(int v: adj[i]) {
                if(d[i]<d[v]) {
                    dnc.addEdge(v,i,inf);
                }
            }
        }
        rep(i,0,n) {
            dnc.addEdge(st,tg2,a[i]);
            dnc.addEdge(st2,i,a[i]);
            ll cur = mid/n;
            if(mid%n) {
                if(i+1 <= (mid%n)) {
                    cur++;
                }
            }
            dnc.addEdge(i,tg,cur);
        }
        dnc.addEdge(tg,st,inf);
        ll cl = dnc.calc(st2,tg2);
        if(cl==sa) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout <<ans <<"\n";
    // clr
    rep(i,0,n) {
        adj[i].clear();
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