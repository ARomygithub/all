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

const int mxn=2e5;
int n,t;
int l[mxn],r[mxn];

void solve() {
    cin >>n;
    vector adj(n, vi());
    vi val(n);
    rep(i,0,n) {
        cin >>l[i] >>r[i];
        val[i] = l[i];
    }
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    function<void(int,int)> dfs1;
    dfs1 = [&](int u, int p) -> void {
        vi vc;
        for(int v: adj[u]) {
            if(v==p) continue;
            dfs1(v,u);
            if(val[v]>val[u]) {
                vc.push_back(val[v]);
            }
        }
        sort(all(vc));
        if(sz(vc)>0) {
            max_self(val[u], min(r[u], vc.back()));
        }
    };
    dfs1(0,-1);
    ll ans = val[0];
    function<void(int,int)> dfs2;
    dfs2 = [&](int u, int p) -> void {
        for(int v: adj[u]) {
            if(v==p) continue;
            ans += max(0, val[v]-val[u]);
            dfs2(v,u);
        }
    };
    dfs2(0,-1);
    cout <<ans <<"\n";
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