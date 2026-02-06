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
int n;
ll a[mxn],b[mxn],x[mxn];
vector<pll> adj[mxn];

void solve() {
    cin >>n;
    rep(i,0,n-1) {
        cin >>a[i] >>b[i] >>x[i];
        adj[i].push_back({a[i],i+1});
        adj[i].push_back({b[i],x[i]-1});
    }
    vector<ll> dp(n, 1e18);
    dp[0] = 0;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,0});
    while(sz(pq)) {
        auto [d,u] = pq.top(); pq.pop();
        if(d>dp[u]) continue;
        for(auto [w,v]: adj[u]) {
            if(d+w<dp[v]) {
                dp[v] = d+w;
                pq.push({dp[v],v});
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