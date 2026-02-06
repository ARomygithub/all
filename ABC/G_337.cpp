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

#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

const int mxn=2e5;
int n;
vector<int> adj[mxn];
int ct[mxn],ctfp[mxn];
ll inner[mxn];

oset<int> dfs(int u, int p=-1) {
    oset<int> s; s.insert(u);
    for(int v: adj[u]) {
        if(v == p) continue;
        auto si = dfs(v, u);
        ctfp[v] = si.order_of_key(u);
        if(sz(s)<sz(si)) {
            s.swap(si);
        }
        for(int vv: si) {
            s.insert(vv);
        }
    }
    ct[u] = s.order_of_key(u);
    // cout <<*s.begin() <<" " <<*it <<"\n";
    return s;
}

void dfs2(int u, int p=-1) {
    ll temp = inner[u]+(u-ct[u]*2);
    for(int v: adj[u]) {
        if(v == p) continue;
        inner[v] +=temp+ct[u]-ctfp[v];
        dfs2(v, u);
    }
}

void solve() {
    cin >>n;
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    ll ans=0;
    rep(i,0,n) {
        ans +=ct[i];
    }
    dfs2(0);
    rep(i,0,n) {
        cout <<ans-ct[i]+inner[i]+i <<" \n"[i==n-1];
    }
    // rep(i,0,n) {
    //     cout <<ct[i] <<" \n"[i==n-1];
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}