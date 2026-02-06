#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
#define pll pair<ll,ll>

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

template <class T>
struct RMQ { // 0-based
  vector<vector<T>> rmq;
  T kInf = numeric_limits<T>::max();
  void build(const vector<T>& V) {
    int n = V.size(), on = 1, dep = 1;
    while (on < n) on *= 2, ++dep;
    rmq.assign(dep, V);
 
    for (int i = 0; i < dep - 1; ++i)
      for (int j = 0; j < n; ++j) {
        rmq[i + 1][j] = min(rmq[i][j], rmq[i][min(n - 1, j + (1 << i))]);
      }
  }
  T query(int a, int b) { // [a, b)
    if (b <= a) return kInf;
    int dep = 31 - __builtin_clz(b - a); // log(b - a)
    return min(rmq[dep][a], rmq[dep][b - (1 << dep)]);
  }
};

struct LCA { // 0-based
  vector<int> enter, depth, exxit;
  vector<vector<int>> G;
  vector<pair<int, int>> linear;
  RMQ<pair<int, int>> rmq;
  int timer = 0;
  LCA() {} 
  LCA(int n) : enter(n, -1), exxit(n, -1), depth(n), G(n), linear(2 * n) {}
  void dfs(int node, int dep) {
    linear[timer] = {dep, node};
    enter[node] = timer++;
    depth[node] = dep;
    for (auto vec : G[node])
    if (enter[vec] == -1) {
      dfs(vec, dep + 1);
      linear[timer++] = {dep, node};
    }
    exxit[node] = timer;
  }
  void add_edge(int a, int b) {
    G[a].push_back(b);
    G[b].push_back(a);
  }
  void build(int root) {
    dfs(root, 0);
    rmq.build(linear);
  }
  int query(int a, int b) {
    a = enter[a], b = enter[b];
    return rmq.query(min(a, b), max(a, b) + 1).second;
  }
  int dist(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[query(a, b)];
  }
};
 

const int mxn=1e5, mxm=5e3;
int n,m;
int d[mxn], anc[mxn][18];
vector<pii> adj[mxn];
ll dist[mxn];

void dfs(int a=0, int p=-1) {
    anc[a][0]=p;
    for(int i=1;i<18;i++) {
        anc[a][i]= ~anc[a][i-1]?anc[anc[a][i-1]][i-1]:-1;
    }
    for(auto [w,b] : adj[a]) {
        if(b==p) continue;
        d[b]=d[a]+1;
        dist[b] = dist[a]+w;
        dfs(b,a);
    }
}


void solve() {
    cin >>n >>m;
    LCA lca = LCA(n);
    for(int i=1;i<n;i++) {
        int u,v, w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
        lca.add_edge(u,v);
    }
    lca.build(0);
    d[0] = 0;
    dist[0] = 0;
    vector<int> player(m);
    set<int> s;
    // priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=0;i<m;i++) {
        cin >>player[i]; player[i]--;
        s.insert(player[i]);
    }
    dfs();
    ll ans= 1e18;
    for(int i=0;i<m;i++) {
        ll temp = 0;
        for(int j=0;j<m;j++) {
            if(player[i]==player[j]) continue;
            int u = player[i], v = player[j];
            temp += dist[u]+dist[v]-dist[lca.query(u,v)]*2;
        }
        min_self(ans, temp);
    }
    assert(ans!=1e18);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}