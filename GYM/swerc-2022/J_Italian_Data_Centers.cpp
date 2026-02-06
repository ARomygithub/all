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

const int mxn=1e2;
int n,m,k,t;
int c[mxn];
vi adj[mxn];
using ipii = pair<int,pii>;

void solve() {
    cin >>n >>m >>k;
    rep(i,0,n) {
        cin >>c[i];
    }
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    rep(r,0,n) {
        vector dp(n, vi(2,1e9));
        priority_queue<ipii,vector<ipii>,greater<ipii>> pq;
        dp[r][0] = 0;
        pq.push({0,{r,0}});
        while(sz(pq)) {
            auto [d,ub] = pq.top(); pq.pop();
            auto [u,b] = ub;
            if(dp[u][b]<d) continue;
            for(int v: adj[u]) {
                int nb = (b + (c[v]!=c[u]))%2;
                if(dp[v][nb] > d+1) {
                    dp[v][nb] = d+1;
                    pq.push({d+1, {v,nb}});
                }
            }
        }
        rep(u,0,n) {
            int cur = 0;
            if(dp[u][0]!=1e9 && dp[u][1]!=1e9) {
                cur = min(min(dp[u][0], dp[u][1]) + k, (dp[u][0] + dp[u][1]+k)/2);
            } else if(dp[u][0]!=1e9) {
                cur = dp[u][0]+k;
            } else if(dp[u][1]!=1e9) {
                cur = dp[u][1]+k;
            }
            max_self(ans, cur);
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}