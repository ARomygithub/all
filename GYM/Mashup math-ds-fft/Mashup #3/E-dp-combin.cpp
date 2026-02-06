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

const int mxn=107;
const ll mod = 1e9+7;
int n;
ll dp[mxn][mxn][mxn];
vi adj[mxn];
int szi[mxn];
ll res[mxn], C[mxn][mxn];

void dfs(int v, int p) {
    szi[v] = 1;
    dp[v][1][0] = 1;
    for(auto to : adj[v]) {
        if(to==p) continue;
        dfs(to, v);
        per(s1,szi[v],-1) {
            per(k1, szi[v], -1) {
                if(dp[v][s1][k1]==0) continue;
                rep(s2,0,szi[to]+1)
                    rep(k2,0,szi[to]+1) {
                        dp[v][s1+s2][k1+k2] = (dp[v][s1+s2][k1+k2] + dp[v][s1][k1]*dp[to][s2][k2]%mod)%mod;
                    }
                dp[v][s1][k1] = 0;
            }
        }
        szi[v] += szi[to];
    }

    rep(i,1,szi[v]+1) {
        rep(j,0,szi[v]+1) {
            dp[v][0][j+1] = (dp[v][0][j+1] + dp[v][i][j]*i%mod)%mod;
        }
    }
}

void solve() {
    rep(i,0,mxn) {
        C[i][0] = C[i][i] = 1;
        rep(j,1,i) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
        }
    }
    cin >>n;
    rep(i,0,n-1) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    rep(i,0,n) {
        res[i] = dp[0][0][i+1];
    }
    res[0] /= n;
    rep(i,1,n) {
        rep(j,0,i-1) {
            res[i] = res[i]*n%mod;
        }
    }
    rep(i,0,n) {
        rep(j,0,i) {
            res[i] = (res[i] - res[j]*C[n-1-j][n-1-i]%mod + mod)%mod;
        }
    }
    per(i,n-1,-1) {
        cout <<res[i] <<" \n"[i==0];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}