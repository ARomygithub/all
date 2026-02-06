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
int n;
vi adj[mxn];
ll ans = 0;
int ct[mxn];

void dfs(int u, int p) {
    if(sz(adj[u])==2) {
        ct[u] = 1;
    }
    ll s = 0;
    for(int v: adj[u]) {
        if(v==p) continue;
        dfs(v, u);
        if(sz(adj[u])==3) {
            ct[u] += ct[v];
        }
        s += ct[v];
    }
    if(sz(adj[u])==3) {
        ll tmp = 0;
        for(int v: adj[u]) {
            if(v==p) continue;
            tmp += (s-ct[v])*ct[v];
        }
        tmp /= 2;
        ans += tmp;
        if(p!=-1 && sz(adj[p])==2) {
            ans += ct[u];
        }
    }
}

void solve() {
    cin >>n;
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}