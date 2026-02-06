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

const int mxn=1e2;
int n,m;
vector<int> adj[mxn];
bool vis[mxn];

void dfs(int u) {
    vis[u] = 1;
    for(int v: adj[u]) {
        if(!vis[v]) dfs(v);
    }
}

void solve() {
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ct=0;
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            ct++;
            dfs(i);
        }
    }
    cout <<ct <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}