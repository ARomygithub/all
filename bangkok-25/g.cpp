#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i= a; i < (b);i++)
#define per(i,a,b) for(int i= a; i > (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
#define fi first
#define se second

const int mxn = 2e5;
int n;
ll x[mxn][3];
vector<pii> adj[mxn];
ll dp[mxn][9], mx[mxn][8];
ll ans = -1e18;

template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

using pli = pair<ll,int>;

void dfs(int u, int p = -1) {
    rep(bit,0,8) {
        dp[u][bit] = dp[u][8];
        rep(j,0,3) {
            if((bit>>j)&1) {
                dp[u][bit] += x[u][j];
            } else {
                dp[u][bit] -= x[u][j];
            }
        }
        mx[u][bit] = dp[u][bit];
    }
    vector vs(8, set<pli>());
    for(auto [w,v]: adj[u]) {
        if(v==p) continue;
        dp[v][8] = dp[u][8]+w; 
        dfs(v,u);
        rep(bit,0,8) {
            max_self(mx[u][bit], mx[v][bit]);
            max_self(ans, mx[v][bit]-dp[u][bit]);
            vs[bit].insert({mx[v][bit],v});
        }
    }
    for(auto [w,v]: adj[u]) {
        if(v==p) continue;
        rep(bit,0,8) {
            auto it = --vs[7-bit].end();
            if(it->se == v) {
                if(it==vs[7-bit].begin()) {
                    continue;
                }
                it--;
            }
            max_self(ans, mx[v][bit]+(it->fi) - dp[u][8]*2);
        }
    }
}


void solve() {
    cin >>n;
    rep(i,1,n) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    rep(i,0,n) {
        rep(j,0,3) {
            cin >>x[i][j];
        }
    }
    dfs(0,-1);
    // dfs2(0,-1);
    cout <<ans <<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    solve();
}