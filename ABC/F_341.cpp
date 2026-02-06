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

const int mxn=5000;
int n,m;
vector<int> adj[mxn];
int w[mxn];
ll a[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rep(i,0,n) {
        cin >>w[i];
    }
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<ll> bobot(n,0);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    rep(i,0,n) {
        pq.push({w[i],i});
    }
    ll ans = 0;
    while(sz(pq)) {
        auto [wi,u] = pq.top(); pq.pop();
        vector<ll> dp(wi+1,1);
        for(int v: adj[u]) {
            if(w[v]>=w[u]) continue;
            per(i,wi,w[v]) {
                max_self(dp[i], dp[i-w[v]]+bobot[v]);
            }
        }
        bobot[u] = dp[wi];
    }
    rep(i,0,n) {
        ans += bobot[i]*a[i];
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}