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
int n,m,t;
vector<pii> adj[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v,w; cin >>u >>v >>w;
        u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    vi dp(n,1e9);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    // queue<pii> pq;
    dp[0] = 0;
    pq.push({0,0});
    while(sz(pq)) {
        auto [u,d] = pq.top(); pq.pop();
        // if(dp[u] < d) continue;
        for(auto [w,v]: adj[u]) {
            if(dp[v] == 1e9) {
                dp[v] = d+w;
                pq.push({v,dp[v]});
            }
        }
    }
    rep(i,1,n) {
        if(dp[i]==1e9) {
            cout <<"-1\n";
        } else {
            cout <<dp[i] <<"\n";
        }
    }
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