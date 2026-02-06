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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e3;
int n;
vector<int> adj[mxn+1];
int rt=1;


int ask(int u, int v) {
    cout <<"? " <<u <<" " <<v <<"\n" <<flush;
    int ret; cin >>ret;
    return ret;
}

void dfs(int u, int p=-1, int larang=-1) {
    rt = u;
    for(int i=0;i<sz(adj[u]);) {
        if(adj[u][i]==p || adj[u][i]==larang) {
            i++;
            continue;
        }
        int idnxt = i+1;
        while(idnxt<sz(adj[u]) && (adj[u][idnxt]==p || adj[u][idnxt]==larang)) {
            idnxt++;
        }
        if(idnxt<sz(adj[u])) {
            int ret = ask(adj[u][i], adj[u][idnxt]);
            if(ret!=u) {
                dfs(ret, u);
                return;
            }
        } else {
            int v = adj[u][i];
            if(sz(adj[v])>1) {
                int vv = adj[v][0];
                if(vv == u) {
                    vv = adj[v][1];
                }
                int ret = ask(u, vv);
                if(ret==v) {
                    dfs(v,u,vv);
                } else if(ret==vv) {
                    dfs(vv,v);
                }
            } else {
                int ret = ask(u, v);
                rt = ret;
            }
        }
        i = idnxt+1;
    }
}

void solve() {
    cin >>n;
    rep(i,1,n) {
        int u,v; cin >>u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout <<"! " <<rt <<"\n" <<flush;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}