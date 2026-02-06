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

const int mxn=20;
int n;
vector<pii> adj[mxn];
ll dp[mxn];

void dfs(int u, int p=-1) {
    for(auto [w,v]: adj[u]) {
        if(v==p) continue;
        dp[v] = dp[u]+1ll*w;
        dfs(v,u);
    }
}

void solve() {
    cin >>n;
    ll s = 0;
    rep(i,1,n) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
        s += 1ll*w;
    }
    dfs(0);
    rep(i,1,n) {
        if(sz(adj[i])==1) {
            for(auto [w,v]: adj[i]) {
                s -= 1ll*w;
            }
        }
    }
    ll mx = 0;
    rep(i,1,n) {
        if(sz(adj[i])>1) {
            max_self(mx, dp[i]);
        }
    }
    cout <<s*2-mx <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}