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

const int mxn=1e4;
int n,m,t;

void clri(int u, int ci) {
    cout <<u <<" " <<ci <<"\n";
    cout <<flush;
}

void solve() {
    cin >>n >>m;
    vector adj(n, vector<int>());
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    function<bool(int,int)> dfs;
    vector<set<int>> vs(2); 
    vector<bool> vis(n,0);
    vector<int> c(n,0);
    dfs = [&](int u, int ci) -> bool {
        vis[u] = 1;
        vs[ci].insert(u);
        c[u] = ci;
        for(int v: adj[u]) {
            if(!vis[v]) {
                bool bip = dfs(v,1-ci);
                if(!bip) return 0;
            } else if(c[u]==c[v]) {
                return 0;
            }
        }
        return 1;
    };
    bool bip = dfs(0,0);
    if(bip) {
        cout <<"Bob\n";
        cout <<flush;
        vector<int> mc(2,-1);
        rep(i,0,n) {
            int c1,c2; cin >>c1;
            if(c1==-1) return;
            cin >>c2;
            if(c2==-1) return;
            if(mc[0]==-1) {
                mc[0] = c1;
            }
            if(c1==mc[0] || c2==mc[0]) {
                if(sz(vs[0])) {
                    int u = *vs[0].begin();
                    clri(u+1, mc[0]);
                    vs[0].erase(vs[0].begin());
                } else {
                    int u = *vs[1].begin();
                    clri(u+1, c1+c2-mc[0]);
                    vs[1].erase(u);
                }
            } else {
                if(mc[1]==-1) {
                    mc[1] = c1;
                }
                if(sz(vs[1])) {
                    int u = *vs[1].begin();
                    clri(u+1, mc[1]);
                    vs[1].erase(u);
                } else {
                    int u = *vs[0].begin();
                    clri(u+1, c1+c2-mc[1]);
                    vs[0].erase(u);
                }
            }
        }
    } else {
        cout <<"Alice\n";
        cout <<flush;
        rep(i,0,n) {
            cout <<"1 2\n";
            cout <<flush;
            int u,ci; cin >>u;
            if(u==-1) return;
            cin >>ci;
            if(ci==-1) return;
        }
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