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

const int mxn=2e5;
int n,m;
int a[mxn];
vector<vi> adj;

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
    adj.resize(n);
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        if(a[u]<=a[v]) {
            adj[u].push_back(v);
        }
        if(a[v]<=a[u]) {
            adj[v].push_back(u);
        }
    }
    vector<int> dp(n,-1e9);
    dp[n-1] = 1;
    scc(adj,[&](vi& v) {
        int mx=-1e9;
        for(int vv: v) {
            for(int vw: adj[vv]) {
                if(comp[vw]!=ncomps) {
                    max_self(dp[vv],dp[vw]+1);
                }
            }
            max_self(mx,dp[vv]);
        }
        for(int vv: v) {
            max_self(dp[vv],mx);
        }
    });
    cout <<max(dp[0],0) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}