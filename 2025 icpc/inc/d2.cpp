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

const int mxn=1e5;
int n,m,t;
vector<pii> adj[mxn];
ll ans = 2e18;
using pli = pair<ll,int>;

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    priority_queue<pli,vector<pli>,greater<pli>> pq;
    vector<ll> dp0(n,1e18), dp1(n,1e18), dp2(n,1e18);
    dp0[0] = 0;
    pq.push({0,0});
    while(sz(pq)) {
        auto [d,u] = pq.top();pq.pop();
        if(dp0[u] < d) continue;
        for(auto& [w,v]: adj[u]) {
            if(dp0[v] > d+w) {
                dp0[v] = d+w;
                pq.push({dp0[v],v});
            }
        }
    }
    dp2[2] = 0;
    pq.push({0,2});
    while(sz(pq)) {
        auto [d,u] = pq.top();pq.pop();
        if(dp2[u] < d) continue;
        for(auto& [w,v]: adj[u]) {
            if(dp2[v] > d+w) {
                dp2[v] = d+w;
                pq.push({dp2[v],v});
            }
        }
    }
    dp1[1] = 0;
    pq.push({0,1});
    while(sz(pq)) {
        auto [d,u] = pq.top();pq.pop();
        if(dp1[u] < d) continue;
        for(auto& [w,v]: adj[u]) {
            int wn = w + (w+1)/2;
            if(dp1[v] > d+wn) {
                dp1[v] = d+wn;
                pq.push({dp1[v],v});
            }
        }
    }    
    rep(i,0,n) {
        min_self(ans, dp0[i]+dp1[i]+dp2[i]);
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