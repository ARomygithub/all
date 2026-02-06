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

const int mxn=1e6;
int n,t;
vi adj[mxn];
int sub[mxn];
ll ans[mxn];

void dfs(int u, int p=-1) {
    sub[u] = 1;
    for(int v: adj[u]) {
        if(v==p) continue;
        dfs(v,u);
        sub[u] += sub[v];
    }
    ans[0] += sub[u];
}

void dfs2(int u, int p=-1) {
    for(int v: adj[u]) {
        if(v==p) continue;
        ans[v] = ans[u] + (n - sub[v]*2);
        dfs2(v,u);
    }
}

void solve() {
    cin >>n;
    rep(i,1,n) {
        int pi; cin >>pi; pi--;
        adj[pi].push_back(i);
    }
    dfs(0,-1);
    dfs2(0,-1);
    ll ansi = 0;
    rep(i,0,n) {
        max_self(ansi, ans[i]);
    }
    cout <<ansi <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}