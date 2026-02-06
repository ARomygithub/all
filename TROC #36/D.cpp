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

const int mxn=1e5;
int n;
vector<int> adj[mxn];
int par[mxn];
bool vis[mxn], npl=0, f=0;

void dfs(int u, int p) {
    // cout <<"d1 " <<u <<" " <<p <<endl;
    par[u] = p;
    vis[u] = 1;
    for(int v: adj[u]) {
        if(v==p) continue;
        if(!vis[v]) {
            dfs(v,u);
        } else {
            if(f) continue;
            f = 1;
            int u2 = u;
            // cout <<"else" <<endl;
            while(u2!=v) {
                // cout <<"dnpl " <<u2 <<endl;
                npl = npl || (sz(adj[u2])==2);
                u2 = par[u2];
            }
            npl = npl || (sz(adj[u2])==2);
        }
    }
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ct = 1;
    rep(i,0,n) {
        ct += sz(adj[i])==1;
    }
    dfs(0,-1);
    if(npl) {
        ct++;
    }
    cout <<n-ct <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}