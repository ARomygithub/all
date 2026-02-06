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

const int mxn=5e5;
int n,m,t;

void solve() {
    cin >>n >>m;
    int ct = 0;
    vector<int> eu(m), ev(m);
    vector<bool> used(m);
    vector adj(n, vector<int>());
    vector adj2(n, map<int,int>());
    vector<int> deg(n, 0);
    rep(i,0,m) {
        cin >>eu[i] >>ev[i]; eu[i]--, ev[i]--;
        int c; cin >>c;
        if(c) {
            adj[eu[i]].push_back(i);
            adj[ev[i]].push_back(i);
            ct++;
            deg[eu[i]]++;
            deg[ev[i]]++;
        } else {
            if(eu[i]!=ev[i] && !adj2[eu[i]].count(ev[i])) {
                adj2[eu[i]][ev[i]] = i;
                adj2[ev[i]][eu[i]] = i;
            }
        }
    }
    vector<bool> vis(n, 0);
    vector<bool> used2(m,0);
    function<void(int)> dfs;
    dfs = [&](int u) -> void {
        vis[u] = 1;
        for(auto [v,id]: adj2[u]) {
            if(!vis[v]) {
                used2[id] = 1;
                deg[u]++; deg[v]++;
                dfs(v);
                if(deg[v]%2) {
                    used2[id] = 0;
                    deg[u]--; deg[v]--;
                }
            }
        }
    };
    rep(i,0,n) {
        if(!vis[i]) {
            dfs(i);
            if(deg[i]%2) {
                cout <<"NO\n";
                return;
            }
        }
    }
    rep(i,0,m) {
        if(used2[i]) {
            ct++;
            adj[eu[i]].push_back(i);
            adj[ev[i]].push_back(i);
        }
    }
    vector<int> ans;
    function<void(int)> dfs2;
    dfs2 = [&](int u) -> void {
        while(sz(adj[u])) {
            int id = adj[u].back(); adj[u].pop_back();
            if(used[id]) continue;
            used[id] = 1;
            dfs2(eu[id]^ev[id]^u);
            ans.push_back(u);
        }
    };
    ans.push_back(0);
    dfs2(0);
    if(sz(ans)==ct+1) {
        cout <<"YES\n";
        cout <<ct <<"\n";
        rep(i,0,sz(ans)) {
            cout <<ans[i]+1 <<" \n"[i==sz(ans)-1];
        }
    } else {
        cout <<"NO\n";
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