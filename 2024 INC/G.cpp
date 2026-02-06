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

const int mxn=2e3;
int n,m;
set<pii> adj[mxn];
int c[mxn];
map<pii,bool> mp;

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

void solve() {
    cin >>n >>m;
    vector<int> ans(m,1);
    vector<pii> ed;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].insert({i,v});
        adj[v].insert({i,u});
        mp[{u,v}] = 1;
        ed.push_back({u,v});
    }
    rep(i,0,n) {
        cin >>c[i];
    }
    vector<bool> vis(n,0);
    function<void(int)> dfs;
    dfs = [&](int u) -> void {
        vis[u] = 1;
        for(auto [id, v]: adj[u]) {
            if(c[u]==c[v]) {
                if(!vis[v]) {
                    if(mp.count({u,v})) {
                        mp[{u,v}] = 1;
                        ans[id] = mp[{u,v}];
                    } else {
                        mp[{v,u}] = 0;
                        ans[id] = mp[{v,u}];
                    }
                    dfs(v);
                } else {
                    if(mp.count({u,v})) {
                        mp[{u,v}] = 0;
                        ans[id] = mp[{u,v}];
                    } else {
                        mp[{v,u}] = 1;
                        ans[id] = mp[{v,u}];
                    }
                }
            } else {
                if(mp.count({u,v})) {
                    mp[{u,v}] = (c[u]>c[v]);
                    ans[id] = mp[{u,v}];
                } else {
                    mp[{v,u}] = (c[v]>c[u]);
                    ans[id] = mp[{v,u}];
                }
            }
        }
    };
    rep(i,0,n) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    vector g(n, vi());
    rep(i,0,m) {
        if(ans[i]) {
            g[ed[i].fi].push_back(ed[i].se);
        } else {
            g[ed[i].se].push_back(ed[i].fi);
        }
    }
    rep(i,0,n) {
        int ct = 0;
        function<void(int)> dfs2;
        vector<bool> vis(n,0);
        dfs2 = [&](int u) -> void {
            vis[u] = 1;
            ct++;
            for(int v: g[u]) {
                if(!vis[v]) {
                    dfs2(v);
                }
            }
        };
        dfs2(i);
        if(ct!=c[i]) {
            cout <<"-1\n";
            return;
        }
    }
    rep(i,0,m) {
        if(ans[i]) {
            cout <<ed[i].fi+1 <<" " <<ed[i].se+1 <<"\n";
        } else {
            cout <<ed[i].se+1 <<" " <<ed[i].fi+1 <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}