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
int n,m;
vector<int> adj[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
    }
    vi dp(n,1e9);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,0});
    while(sz(pq)) {
        auto [d,u] = pq.top(); pq.pop();
        if(dp[u]<d) continue;
        for(auto v: adj[u]) {
            if(dp[v]>d+1) {
                dp[v] = d+1;
                pq.push({dp[v],v});
            }
        }
    }
    if(dp[0]==1e9) {
        cout <<"-1\n";
    } else {
        cout <<dp[0] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}