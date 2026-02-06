#include <bits/stdc++.h>

using namespace std;

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int mxn = 1e5+1;
// const int mxm = 1e6;
int n, l;
vector<vector<int>> adj(mxn);
vector<vector<int>> adj_tree(mxn);
vector<pii> edge;
vector<int> vis(mxn);
vector<pii> tree;
// vector<int> vis_edge(mxm);
vector<pii> exclude;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector<int> dp;
vector<int> par;

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj_tree[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

void dfs2(int u, int p, int dpth) {
    dp[u] = dpth;
    par[u] = p;
    for(auto v: adj_tree[u]) {
        if(v!=p) {
            dfs2(v, u, dpth+1);
        }
    }
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    dp.resize(n);
    par.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
    dfs2(root, root, 0);
}


int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0; i<2*n-3; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
        edge.push_back({u, v});
    }
    int m = edge.size();
    // cout << "tree:\n";
    for(int i=0; i<m; i++) {
        auto [u, v] = edge[i];
        if(!vis[u] || !vis[v]) {
            tree.push_back(edge[i]);
            vis[u] = 1;
            vis[v] = 1;
            // cout << u << " " << v << "\n";
            // vis_edge[i] = 1;
        }
        else {
            exclude.pb(edge[i]);
        }
    }


    for(auto [p, q]: tree){
        adj_tree[p].pb(q);
        adj_tree[q].pb(p);
    }

    preprocess(0);
    map<int, pair<int, int>> bs;
    for(auto [p, q]: exclude) {
        int id1 = lca(p, q);
        int dist = dp[p] + dp[q] - 2 * dp[id1] + 1;
        if(dist < 3) {
            continue;
        }
        if(bs.count(dist)) {
            auto [p1, q1] = bs[dist];
            int id2 = lca(p1, q1);
            deque<int> ans1, ans2;
            while(p != id1) {
                ans1.push_back(p+1);
                p = par[p];
            }
            ans1.push_front(id1+1);
            while(q != id1) {
                ans1.push_front(q+1);
                q = par[q];
            }
            
            while(p1 != id2) {
                ans2.push_back(p1+1);
                p1 = par[p1];
            }
            ans2.push_front(id2+1);
            while(q1 != id2) {
                ans2.push_front(q1+1);
                q1 = par[q1];
            }
            int mx = ans1.size();
            for(int i=0; i<mx-1; i++){
                if(ans1[i] == ans2[i] && ans1[i+1] == ans2[i+1]) {
                    reverse(ans1.begin(), ans1.end());
                }
            }

            cout << mx << "\n";
            for(int i=0; i<mx; i++) {
                cout << ans1[i] << " \n"[i==mx-1];
            }
            for(int i=0; i<mx; i++) {
                cout << ans2[i] << " \n"[i==mx-1];
            }

            break;
        }
        bs[dist] = mp(p, q);
    }

    return 0;
}