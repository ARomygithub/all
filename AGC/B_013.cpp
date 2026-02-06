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
int n,m;
vector<int> adj[mxn],ans;
bool vis[mxn];
bool enAll = 0;

void dfs(int u) {
    ans.push_back(u);
    vis[u] = 1;
    bool en = 1;
    for(int v: adj[u]) {
        if(enAll) return; 
        if(!vis[v]) {
            en = 0;
            dfs(v);
        }
    }
    if(en) {
        enAll = 1;
    }
}

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    reverse(ans.begin(),ans.end());
    ans.pop_back();
    enAll = 0;
    dfs(0);
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i]+1 <<" \n"[i==sz(ans)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}