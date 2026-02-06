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

const int mxn=1e5;
const ll mod=998244353;
// 3006703054056749
int n,m;
vector<int> adj[mxn], adj2[mxn];
int in[mxn],ct[mxn];
// ll dp[mxn],dp2[mxn];
ll dp2[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v;cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        in[v]++;
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    // dp[0] = 1;
    pq.push(0);
    while(sz(pq)) {
        auto u = pq.top(); pq.pop();
        // assert(ini==0);
        for(int v: adj[u]) {
            // dp[v] =(dp[v]+dp[u])%mod;
            adj2[v].push_back(u);
            ct[v]++;
            if(ct[v]==in[v]) {
                pq.push(v);
            }
        }
    }
    fill(ct,ct+n,0);
    pq.push(0);
    while(sz(pq)) {
        auto u = pq.top(); pq.pop();
        for(int v: adj[u]) {
            ct[v]++;
            if(sz(adj2[v])==1) {
                dp2[v]++;
                dp2[v] +=dp2[u];
            }
            if(ct[v]==in[v]) {
                pq.push(v);
            }
        }
    }
    rep(i,0,n) {
        cout <<dp2[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}