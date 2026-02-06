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

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vi time, path, ret;
	RMQ<int> rmq;

	LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vi>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

const int mxn=2e5;
int n,t;
ll ans = 0;
int c[mxn];

void solve() {
    cin >>n;
    vector<vector<int>> adj(n);
    set<int> sc;
    rep(i,0,n) {
        cin >>c[i];
        sc.insert(c[i]);
    }
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LCA lca(adj);
    vector adj2(n, vector<int>());
    map<int,vector<pii>> mpvec;
    rep(i,0,n) {
        mpvec[c[i]].push_back({lca.time[i], i});
    }
    ans = 0;
    auto solve_aux = [&](int ci) -> void {
        vector<pii> vec = mpvec[ci];
        set<pii> aux;
        sort(vec.begin(),vec.end());
        rep(i,0,sz(vec)) {
            aux.insert(vec[i]);
            if(i+1<sz(vec)) {
                int u = lca.lca(vec[i].se,vec[i+1].se);
                aux.insert({lca.time[u], u});
            }
        }
        stack<int> st;
        for(auto [ti, u]: aux) {
            if(sz(st)) {
                while(lca.lca(st.top(), u) != st.top()) {
                    st.pop();
                }
                adj2[st.top()].push_back(u);
                st.push(u);
            } else {
                st.push(u);
            }
        }
        int r = (*aux.begin()).se;
        function<ll(int,int)> dfs;
        dfs = [&](int u, int p=-1) -> ll {
            ll si = 0;
            ll s2 = 0;
            for(int v: adj2[u]) {
                if(v==p) continue;
                ll sv = dfs(v,u);
                si += sv;
                s2 += sv*sv;
            }
            if(c[u]==ci) {
                ans += si;
                return 1;
            } else {
                ans += (si*si - s2)/2;
                return si;
            }
        };
        dfs(r,-1);
        for(auto [ti,u]: aux) {
            adj2[u].clear();
        }
    };
    for(int ci : sc) {
        solve_aux(ci);
    }
    cout <<ans <<"\n";
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