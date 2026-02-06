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
ll n,t;

void solve() {
    cin >>n;
    vector adj(n, vi());
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi st(n,0);
    ll ans = 0;
    ll ctl = 0;
    ll ctpl = 0;
    rep(i,0,n) {
        if(sz(adj[i])==1) {
            st[i] = 1;
            ctl++;
        }
    }
    rep(i,0,n) {
        if(st[i]==1) continue;
        for(int v: adj[i]) {
            if(st[v]==1) {
                st[i] = 2;
                ctpl++;
                break;
            }
        }
    }
    ans += ctl*(n-ctl);
    vi dp(n,0);
    function<void(int,int)> dfs;
    dfs = [&](int u, int p) -> void {
        dp[u] = (st[u]==0);
        int ctnl = 0;
        for(int v: adj[u]) {
            if(v==p) continue;
            dfs(v,u);
            ctnl += (st[v]!=1);
            dp[u] += dp[v];
        }
        if(st[u]==2) {
            ans += (n-ctl-ctpl - dp[u])*(ctnl);
            int x = 0;
            if(p>=0) {
                x = (st[p]!=1);
            }
            for(int v: adj[u]) {
                if(v==p) continue;
                if(st[v]!=1) {
                    ans += 1ll*dp[v]*(ctnl-1+x);
                }
            }
        }
    };
    dfs(0,-1);
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