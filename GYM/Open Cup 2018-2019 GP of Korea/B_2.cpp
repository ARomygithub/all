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

const int mxn=1e5;
int n,m;
set<int> adj[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        if(u>v) swap(u,v);
        adj[u].insert(v);
        adj[v].insert(u);
    }
    queue<int> q;
    rep(i,0,n) {
        if(sz(adj[i])==2) {
            q.push(i);
        }
    }
    while(sz(q)) {
        auto u = q.front(); q.pop();
        if(sz(adj[u])!=2) continue;
        auto a = (*adj[u].begin());
        auto b = (*(++adj[u].begin()));
        adj[u].clear();
        adj[a].erase(u);
        adj[b].erase(u);
        adj[a].insert(b);
        adj[b].insert(a);
        if(sz(adj[a])==2) {
            q.push(a);
        }
        if(sz(adj[b])==2) {
            q.push(b);
        }
    }
    int ct = 0;
    rep(i,0,n) {
        ct += sz(adj[i]);
    }
    if(ct==2) {
        cout <<"Yes\n";
    } else {
        cout <<"No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}