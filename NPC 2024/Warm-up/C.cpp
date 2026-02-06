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

const int mxn=2e3,mxk=1e5+1;
ll n,k;
ll t[mxn];
vi adj[mxn];
ll ans = 0;

void dfs(int u, int p, ll sm) {
    if(sm<=k) {
        max_self(ans, sm);
    } else {
        // return;
    }
    for(int v: adj[u]) {
        if(v==p) continue;
        dfs(v,u, sm+t[v]);
    }
}

void solve() {
    cin >>n;
    // assert(n<=mxn);
    rep(i,0,n) {
        cin >>t[i];
    }
    vector<pii> e;
    int mn = n;
    rep(i,1,n) {
        int u,v; cin >>u >>v;
        // assert(u<n && u>=0 && v<n && v>=0);
        if(u==v) continue;
        e.push_back({u,v});
        min_self(mn,min(u,v));
        // adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    for(auto [u,v]: e) {
        // if(mn==0) {
        //     // assert(u<n && v<n);
        //     if(u<n && v<n) {
        //         adj[u].push_back(v);
        //         adj[v].push_back(u);
        //     }
        // } else if(mn==1) {
            // assert(u<=n && v<=n);
            u--,v--;
            if(u<n && v<n && u>=0 && v>=0) {
                adj[u].push_back(v);
                // adj[v].push_back(u);
            }
        // } else {
        //     // assert(false);
        // }
    }
    cin >>k;
    dfs(0,-1,t[0]);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}