#include <bits/stdc++.h>
using namespace std;

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

const int mxn=3e5;
int n,m,t;
vector<int> adj[mxn];

void solve() {
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> clr(n,-1);
    vector<int> red;
    function<void(int,int)> dfs;
    dfs = [&](int u, int p) -> void {
        clr[u] = 1;
        red.push_back(u);
        for(int v: adj[u]) {
            if(clr[v]==-1) {
                clr[v] = 0;
            }
        }
        for(int v: adj[u]) {
            if(clr[v]==0 && v!=p) {
                for(int vv: adj[v]) {
                    if(clr[vv]==-1) {
                        dfs(vv,v);
                    }
                }
            }
        }
    };
    dfs(0,-1);
    bool flag=1;
    for(int i=0;i<n&&flag;i++) {
        if(clr[i]==-1) flag=0;
    }
    if(flag) {
        cout <<"YES\n";
        cout <<sz(red) <<"\n";
        for(int i=0;i<sz(red);i++) {
            cout <<red[i]+1 <<" \n"[i==sz(red)-1];
        }
    } else {
        cout <<"NO\n";
    }
    for(int i=0;i<n;i++) {
        adj[i].clear();
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