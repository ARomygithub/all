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

const int mxn=2e5;
int n,m;
vector<int> adj[mxn];
bool ok[mxn],vis[mxn],act[mxn];

void dfs(int u) {
    vis[u] = 1;
    act[u] = 1;
    for(int v: adj[u]) {
        if(act[v]) {
            ok[u] = 1;
        } else {
            if(!vis[v]) {
                dfs(v);
            }
            ok[u] = ok[u]||ok[v];
        }
    }
    act[u] = 0;
}

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
    }
    rep(i,0,n) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    int ct = 0;
    rep(i,0,n) {
        ct += ok[i];
    }
    cout <<ct <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}