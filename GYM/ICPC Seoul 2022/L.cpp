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
	vi time, path, ret,depth,pr;
	RMQ<int> rmq;

	LCA(vector<vi>& C) : time(sz(C)), depth(sz(C),0),pr(sz(C),0), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vi>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
            depth[y] = depth[v]+1;
            pr[y] = v;
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	int dist(int a,int b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

void solve() {
    cin >>n;
    UF uf(n);
    vector adj(n, vi()),adj2(n,vi());
    rep(i,0,n*2-3) {
        int u,v; cin >>u >>v; u--,v--;
        if(uf.join(u,v)) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            adj2[u].push_back(v);
        }
    }
    vector st(n, set<int>());
    rep(i,0,n) {
        st[uf.find(i)].insert(i);
    }
    rep(i,0,n) {
        if(sz(st[i])==0) continue;
        map<int,int> toId,toU;
        int id= 0;
        for(auto u: st[i]) {
            toId[u] = id;
            toU[id] = u;
            id++;
        }
        vector adji(id, vi());
        for(auto u: st[i]) {
            for(auto v: adj[u]) {
                adji[toId[u]].push_back(toId[v]);
                adji[toId[v]].push_back(toId[u]);
            }   
        }
        LCA lca(adji);
        map<int,pii> mp;
        auto crtAns = [&](vi& ans, int u, int v) -> void {
            vi tmp1, tmp2;
            int iu = toId[u], iv=toId[v];
            int lc = lca.lca(iu,iv);
            int x = iu;
            while(x!=lc) {
                tmp1.push_back(toU[x]);
                x = lca.pr[x];
            }
            x = iv;
            while(x!=lc) {
                tmp2.push_back(toU[x]);
                x = lca.pr[x];
            }
            rep(j,0,sz(tmp1)) {
                ans.push_back(tmp1[j]);
            }
            ans.push_back(toU[lc]);
            per(j,sz(tmp2)-1,-1) {
                ans.push_back(tmp2[j]);
            }
        };
        for(auto u: st[i]) {
            for(auto v: adj2[u]) {
                int iu = toId[u], iv=toId[v];
                int ds = lca.dist(iu,iv);
                if(mp.count(ds)) {
                    cout <<ds+1 <<"\n";
                    vi ans1,ans2;
                    crtAns(ans1, u,v);
                    auto [u2,v2] = mp[ds];
                    crtAns(ans2, u2, v2);
                    rep(j,0,sz(ans1)) {
                        cout <<ans1[j]+1 <<" \n"[j==sz(ans1)-1];
                    }
                    rep(j,0,sz(ans2)) {
                        cout <<ans2[j]+1 <<" \n"[j==sz(ans2)-1];
                    }
                    return;
                }
                mp[ds] = {u,v};
            }
        }
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