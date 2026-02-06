#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,m;
int cost[mxn];
pii h[mxn];
bool vis[mxn];
vector<int> adj[mxn];

void dfs(int u, int hh) {
    vis[u] = 1;
    for(int v: adj[u]) {
        if(!vis[v]) {
            min_self(cost[v], hh);
            dfs(v, cost[v]);
        }
    }
}

void solve() {
    cin >>n >>m;
    for(int i=0;i<n;i++) {
        cin >>cost[i];
        h[i].fi = cost[i];
        h[i].se = i;
    }
    for(int i=0;i<m;i++) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
    }
    sort(h,h+n);
    for(int i=0;i<n;i++) {
        if(!vis[h[i].se]) {
            dfs(h[i].se,h[i].fi);
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++) {
        ans +=cost[i];
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}