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

const int mxn=2e5;
int n,m;
int deg[mxn+1];
vector<int> adj[mxn+1];
bool vis[mxn+1];

void dfs(int u, int p=-1) {
    // cout <<"hai\n";
    // cout <<flush;
    vis[u]=1;
    for(auto v: adj[u]) {
        if(v==p) continue;
        dfs(v,u);
    }
}

void solve() {
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int u,v; cin >>u >>v;
        deg[u]++, deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(m!=n-1) {
        cout <<"No\n";
        return;
    }
    int u=-1;
    for(int i=1;i<=n;i++) {
        if(deg[i]!=1 && deg[i]!=2) {
            cout <<"No\n";
            return;
        } else if(deg[i]==1) {
            u = i;
        }
    }
    if(u==-1) {
        cout <<"No\n";
        return;
    }
    dfs(u);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            cout <<"No\n";
            return;
        }
    }
    cout <<"Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}