#include <bits/stdc++.h>
using namespace std;

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,t;
int a[mxn];
vector<int> adj[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    for(int i=1;i<n;i++) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans=0;
    vector<ll> add(n,0);
    vector<int> siz(n,0);
    function<void(int,int)> dfs1,dfs2;
    dfs1 = [&](int u, int p) -> void {
        siz[u] = 1;
        for(int v: adj[u]) {
            if(v==p) continue;
            dfs1(v,u);
            siz[u] +=siz[v];
            ans +=1ll * siz[v] * (a[u]^a[v]);
            add[v] = 1ll * (n-siz[v]*2) * (a[u]^a[v]);
        }
    };
    dfs1(0,-1);
    dfs2 = [&](int u, int p) -> void {
        for(int v: adj[u]) {
            if(v==p) continue;
            add[v] +=add[u];
            dfs2(v,u);
        }
    };
    dfs2(0,-1);
    for(int i=0;i<n;i++) {
        cout <<ans+add[i] <<" \n"[i==n-1];
    }
    for(int i=0;i<n;i++) {
        adj[i].clear();
    }
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