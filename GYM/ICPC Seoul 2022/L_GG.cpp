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

const int mxn=1e5;
int n;

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


void solve() {
    cin >>n;
    UF uf(n);
    vector<pii> exc;
    vector adj(n, vi());
    rep(i,0,n*2-3) {
        int u,v; cin >>u >>v; u--,v--;
        if(uf.join(u,v)) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            exc.push_back({u,v});
        }
    }
    vi par,dp;
    par.resize(n);
    iota(par.begin(),par.end(),0);
    dp.resize(n,0);
    function<void(int,int)> dfs;
    dfs = [&](int u, int pr) -> void {
        for(int v: adj[u]) {
            if(v==pr) continue;
            par[v] = u;
            dp[v] = dp[u]+1;
            dfs(v,u);
        }
    };
    rep(i,0,n) {
        if(par[i]==i) {
            dfs(i,-1);
        }
    }
    auto tbl = treeJump(par);
    map<int,pii> mp;
    auto crtAns = [&](vi& ans, int u, int v) -> void {
        vi tmp1, tmp2;
        int lc = lca(tbl, dp, u,v);
        int x = u;
        while(x!=lc) {
            tmp1.push_back(x);
            x = par[x];
        }
        x = v;
        while(x!=lc) {
            tmp2.push_back(x);
            x = par[x];
        }
        rep(i,0,sz(tmp1)) {
            ans.push_back(tmp1[i]);
        }
        ans.push_back(lc);
        per(i,sz(tmp2)-1,-1) {
            ans.push_back(tmp2[i]);
        }
    };
    for(auto [u,v]: exc) {
        int ds = dp[u]+dp[v]-dp[lca(tbl, dp,u,v)]*2;
        if(mp.count(ds)) {
            cout <<ds+1 <<"\n";
            vi ans1,ans2;
            crtAns(ans1, u,v);
            auto [u2,v2] = mp[ds];
            crtAns(ans2, u2, v2);
            rep(i,0,sz(ans1)) {
                cout <<ans1[i]+1 <<" \n"[i==sz(ans1)-1];
            }
            rep(i,0,sz(ans2)) {
                cout <<ans2[i]+1 <<" \n"[i==sz(ans2)-1];
            }
            return;
        }
        mp[ds] = {u,v};
    }
    int ds = n-2;
    auto [un,vn] = mp[n-1];
    auto [u2,v2] = mp[2];
    if(dp[un]>dp[vn]) swap(un,vn);
    if(dp[u2]>dp[v2]) swap(u2,v2);
    auto toP = [&](vi& ans, int u, int p) -> void {
        while(u!=p) {
            ans.push_back(u);
            u = par[u];
        }
    };
    if(mp.count(ds)) {
        cout <<ds+1 <<"\n";
        vi ans1,ans2;
        toP(ans1, vn, v2);
        ans1.push_back(v2);
        toP(ans1, u2, un);
        ans1.push_back(un);
        auto [ux,vx] = mp[ds];
        crtAns(ans2, ux, vx);
        rep(i,0,sz(ans1)) {
            cout <<ans1[i]+1 <<" \n"[i==sz(ans1)-1];
        }
        rep(i,0,sz(ans2)) {
            cout <<ans2[i]+1 <<" \n"[i==sz(ans2)-1];
        }        
        return;
    }
    assert(false);
    cout <<"-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}