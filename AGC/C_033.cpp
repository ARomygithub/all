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

const int mxn=2e5;
int n, d[mxn];
vector<int> adj[mxn];
int diam = 0;

int dfs(int u, int p=-1) {
    int ret = d[u];
    priority_queue<int> pq;
    for(int v: adj[u]) {
        if(v==p) continue;
        d[v] = d[u]+1;
        int retc = dfs(v,u);
        pq.push(retc);
        max_self(ret, retc);
    }
    if(sz(pq)>=2) {
        int d1 = pq.top(); pq.pop();
        int d2 = pq.top(); pq.pop();
        max_self(diam, d1+d2-d[u]*2);
    }
    max_self(diam, ret-d[u]);
    return ret;
}

void solve() {
    cin >>n;
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    dfs(0);
    // cout <<diam <<"\n";
    if((diam%3)==1) {
        cout <<"Second\n";
    } else {
        cout <<"First\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}