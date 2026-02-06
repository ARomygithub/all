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

const int mxn=2e5;
int n,m;
vector<pii> adj[mxn],adj2[mxn];
bool vis[mxn];
ll ans[mxn];

void dfs(int u) {
    for(auto [w,v]: adj[u]) {
        if(!vis[v]) {
            vis[v] = 1;
            ans[v] = ans[u]+w;
            dfs(v);
        }
    }
    for(auto [w,v]: adj2[u]) {
        if(!vis[v]) {
            vis[v] = 1;
            ans[v] = ans[u] + w;
            dfs(v);
        }
    }
}

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj2[v].push_back({-w,u});
    }
    rep(i,0,n) {
        if(!vis[i]) {
            vis[i] = 1;
            dfs(i);
        }
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}