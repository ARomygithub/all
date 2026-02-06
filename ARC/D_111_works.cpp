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

const int mxn=1e2;
int n,m;
set<pii> adj[mxn];
int c[mxn];
map<pii,bool> mp;

void solve() {
    cin >>n >>m;
    vector<int> ans(m,1);
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].insert({i,v});
        adj[v].insert({i,u});
        mp[{u,v}] = 1;
    }
    rep(i,0,n) {
        cin >>c[i];
    }
    vector<bool> vis(n,0);
    function<void(int)> dfs;
    dfs = [&](int u) -> void {
        vis[u] = 1;
        for(auto [id, v]: adj[u]) {
            if(c[u]==c[v]) {
                if(!vis[v]) {
                    if(mp.count({u,v})) {
                        mp[{u,v}] = 1;
                        ans[id] = mp[{u,v}];
                    } else {
                        mp[{v,u}] = 0;
                        ans[id] = mp[{v,u}];
                    }
                    dfs(v);
                } else {
                    if(mp.count({u,v})) {
                        mp[{u,v}] = 0;
                        ans[id] = mp[{u,v}];
                    } else {
                        mp[{v,u}] = 1;
                        ans[id] = mp[{v,u}];
                    }
                }
            } else {
                if(mp.count({u,v})) {
                    mp[{u,v}] = (c[u]>c[v]);
                    ans[id] = mp[{u,v}];
                } else {
                    mp[{v,u}] = (c[v]>c[u]);
                    ans[id] = mp[{v,u}];
                }
            }
        }
    };
    rep(i,0,n) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    rep(i,0,m) {
        if(ans[i]) {
            cout <<"->\n";
        } else {
            cout <<"<-\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}