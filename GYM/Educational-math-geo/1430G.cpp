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
typedef pair<pll,int> plli;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=18;
int n,m;
vector<pii> adj[mxn], adj2[mxn];
vector<int> topo;
bool vis[mxn];
ll c[mxn];

void dfs(int u) {
    vis[u] = 1;
    for(auto [w,v]: adj2[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
    topo.push_back(u);
}

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj2[v].push_back({w,u});
        c[u] += w;
        c[v] -= w;
    }
    vector dp(n, vector<ll>(1<<n, 1e18));
    rep(i,0,n) {
        dp[i][0] = 0;
    }
    vector p(n, vector<int>(1<<n,0));
    rep(i,0,n) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    rep(val,0,n) {
        rep(i,0,n) {
            int u = topo[i];
            int mini = 0;
            for(auto [w,v]: adj[u]) {
                mini += (1<<v);
            }
            rep(bit,0,1<<n) {
                if((bit>>u)&1) {
                    if((bit&mini)!=mini) continue;
                    if(val>0 && dp[val-1][bit^(1ll<<u)]!=1e18) {
                        ll temp = dp[val-1][bit^(1ll<<u)] + c[u]*val;
                        if(temp < dp[val][bit]) {
                            dp[val][bit] = temp;
                            p[val][bit] = (1<<u);
                        }
                    }    
                    ll temp = dp[val][bit^(1<<u)] + c[u]*val;         
                    if(temp < dp[val][bit] && dp[val][bit^(1<<u)]!=1e18) {
                        dp[val][bit] = temp;
                        p[val][bit] = p[val][bit^(1<<u)] + (1<<u);
                    } 
                }
            }
        }
    }
    pii st = {-1,-1};
    ll cur = 1e18;
    rep(i,0,n) {
        if(dp[i][(1<<n)-1]<cur) {
            cur = dp[i][(1<<n)-1];
            st = {i, (1<<n)-1};
        }
    }
    // cout <<cur <<endl;
    vector<ll> ans(n);
    while(st.se>0) {
        int sub = p[st.fi][st.se];
        rep(i,0,n) {
            if((sub>>i)&1) {
                ans[i] = st.fi;
            }
        }
        st = {st.fi-1, st.se^sub}; 
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}