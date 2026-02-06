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

const int mxn=2e5;
int n,m;
int a[mxn];
vector<int> adj[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        if(a[u]<=a[v]) {
            adj[u].push_back(v);
        }
        if(a[v]<=a[u]) {
            adj[v].push_back(u);
        }
    }
    vector<int> dp(n,0);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dp[0] = 1;
    pq.push({1,0});
    while(sz(pq)) {
        auto [d,u] = pq.top(); pq.pop();
        if(dp[u]>d) continue;
        for(int v: adj[u]) {
            if(a[v]>=a[u]) {
                int di = d+(a[v]>a[u]);
                if(di>dp[v]) {
                    dp[v] = di;
                    pq.push({di,v});
                }
            }
        }
    }
    cout <<dp[n-1] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}