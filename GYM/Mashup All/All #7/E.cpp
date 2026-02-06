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
int c[mxn];
vi adj[mxn];
vector ans(mxn, vector<ll>(2,1e18));
bool vis[mxn][2], used[mxn];

void dfs(int u, int p) {
    if(sz(adj[u])==1 && p!=-1) {
        ans[u][0] = c[u];
        ans[u][1] = 0;
        return;
    }
    ll sm = 0, mn = 1e18;
    for(int v: adj[u]) {
        if(v==p) continue;
        dfs(v,u);
        sm += ans[v][0];
        min_self(mn, ans[v][1]-ans[v][0]);
    }
    ans[u][0] = sm + min(0ll,mn + c[u]);
    ans[u][1] = sm + mn;
}

void dfs2(int u, int p, int mark) {
    vis[u][mark] = 1;
    if(sz(adj[u])==1 && p!=-1) {
        if(mark==0) {
            used[u] = 1;
        }
        return;
    }
    ll sm = 0, mn = 1e18;
    for(int v: adj[u]) {
        if(v==p) continue;
        sm += ans[v][0];
        min_self(mn, ans[v][1]-ans[v][0]);
    }
    vi vmn;
    for(int v: adj[u]) {
        if(v==p) continue;
        if(mn==ans[v][1]-ans[v][0]) {
            vmn.push_back(v);
        }
    }
    if(mark) {
        if(sz(vmn)>1) {
            for(int v: adj[u]) {
                if(v==p) continue;
                if(!vis[v][0]) {
                    dfs2(v,u,0);
                }
            }
        } else {
            for(int v: adj[u]) {
                if(v==p || v==vmn[0]) continue;
                if(!vis[v][0]) {
                    dfs2(v,u,0);
                }
            }
        }
        for(int v: vmn) {
            if(!vis[v][1]) {
                dfs2(v,u,1);
            }
        }        
    } else {
        if(mn+c[u]<=0) {
            used[u] = 1;
            if(sz(vmn)>1) {
                for(int v: adj[u]) {
                    if(v==p) continue;
                    if(!vis[v][0]) {
                        dfs2(v,u,0);
                    }
                }
            } else {
                for(int v: adj[u]) {
                    if(v==p || v==vmn[0]) continue;
                    if(!vis[v][0]) {
                        dfs2(v,u,0);
                    }
                }
            }
            for(int v: vmn) {
                if(!vis[v][1]) {
                    dfs2(v,u,1);
                }
            }
        }
        if(0<=mn+c[u]) {
            for(int v: adj[u]) {
                if(v==p) continue;
                if(!vis[v][0]) {
                    dfs2(v,u,0);
                }
            }
        }
    }
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>c[i];
    }
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    dfs2(0, -1, 0);
    vi vans;
    rep(i,0,n) {
        if(used[i]) {
            vans.push_back(i+1);
        }
    }
    cout <<ans[0][0] <<" " <<sz(vans) <<"\n";
    rep(i,0,sz(vans)) {
        cout <<vans[i] <<" \n"[i==sz(vans)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}