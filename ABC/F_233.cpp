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

vector<vi> treeJump(vi& P){
	int on = 1, d = 1;
	while(on < sz(P)) on *= 2, d++;
	vector<vi> jmp(d, P);
	rep(i,1,d) rep(j,0,sz(P))
		jmp[i][j] = jmp[i-1][jmp[i-1][j]];
	return jmp;
}

int jmp(vector<vi>& tbl, int nod, int steps){
	rep(i,0,sz(tbl))
		if(steps&(1<<i)) nod = tbl[i][nod];
	return nod;
}

int lca(vector<vi>& tbl, vi& depth, int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	a = jmp(tbl, a, depth[a] - depth[b]);
	if (a == b) return a;
	for (int i = sz(tbl); i--;) {
		int c = tbl[i][a], d = tbl[i][b];
		if (c != d) a = c, b = d;
	}
	return tbl[0][a];
}

const int mxn=1e3;
int n,m;
int pos[mxn],val[mxn];
vector<pii> adj[mxn];
vi par(mxn), d(mxn), nord, parid(mxn);
bool vis[mxn];
set<int> snord,sval;

void dfs(int u) {
    vis[u] = 1;
    for(auto [v,id]: adj[u]) {
        if(!vis[v]) {
            par[v] = u;
            parid[v] = id;
            d[v] = d[u]+1;
            dfs(v);
        }
    }
}

void dfs2(int u) {
    vis[u] = 0;
    snord.insert(u);
    sval.insert(val[u]);
    for(auto [v,id]: adj[u]) {
        if(vis[v]) {
            dfs2(v);
        }
    }
    nord.push_back(u);
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        int temp; cin >>temp; temp--;
        pos[temp] = i;
        val[i] = temp;
    }
    cin >>m;
    rep(i,0,m) {
        int u,v; cin >>u >>v;u--,v--;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    bool ok = 1;
    vector<int> ans;
    rep(i,0,n) {
        if(!vis[i]) {
            par[i] = i;
            d[i] = 0;
            dfs(i);
        }
    }
    auto tbl = treeJump(par);
    auto swp = [&](int u, int v) -> void {
        swap(val[u],val[v]);
        pos[val[u]] = u;
        pos[val[v]] = v;
    };
    rep(i,0,n) {
        if(vis[i]) {
            nord.clear();
            snord.clear();
            sval.clear();
            dfs2(i);
            // cek set
            auto it = snord.begin();
            auto it2 = sval.begin();
            while(it!=snord.end()) {
                ok &= (*it)==(*it2);
                it++; it2++;
            }
            if(!ok) {
                cout <<"-1\n";
                return;
            }
            rep(j,0,sz(nord)) {
                int u = nord[j];
                int lc = lca(tbl,d, u, pos[u]);
                int v = pos[u];
                while(v!=lc) {
                    ans.push_back(parid[v]);
                    swp(v,par[v]);
                    v = par[v];
                }
                int u2 = u;
                vi v2, id2;
                while(u2!=lc) {
                    v2.push_back(u2);
                    id2.push_back(parid[u2]);
                    u2 = par[u2];
                }
                v2.push_back(lc);
                per(k,sz(id2)-1,-1) {
                    ans.push_back(id2[k]);
                }
                per(k,sz(v2)-1,0) {
                    swp(v2[k],v2[k-1]);
                }
            }
        }
    }
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i]+1 <<" \n"[i==sz(ans)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}