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
int ct=0, id=0;
vector<int> adj[mxn];
bool vis[mxn];

void dfs(int u) {
    vis[u] = 1;
    ct++;
    for(auto v: adj[u]) {
        if(!vis[v]) dfs(v);
    }
}

void solve() {
    cin >>n >>m;
    map<string,int> mp;
    for(int i=0;i<m;i++) {
        string u,v; cin >>u >>v;
        if(!mp.count(u)) {
            mp[u] = id;
            id++;
        }
        if(!mp.count(v)) {
            mp[v] = id;
            id++;
        }
        int ui = mp[u], vi=mp[v];
        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
    }
    ll ans=0;
    for(int i=0;i<n;i++) {
        ct = 0;
        if(!vis[i]) {
            dfs(i);
            ans +=1ll*ct*(n-ct);
        }
    }
    ans /=2ll;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}