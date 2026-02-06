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

const int mxn=100;
int n,e,tmi,m,t;

void solve() {
    cin >>n >>e >>tmi;
    cin >>m;
    vector<vector<pii>> adj(n);
    e--;
    rep(i,0,m) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[v].push_back({w,u});
    }
    vi dp(n, 1e9);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dp[e] = 0;
    pq.push({0,e});
    while(sz(pq)) {
        auto du = pq.top(); pq.pop();
        int d = du.fi, u = du.se;
        for(auto wv: adj[u]) {
            int w = wv.fi, v = wv.se;
            if(d+w < dp[v]) {
                dp[v] = d+w;
                pq.push({dp[v],v});
            }
        }
    }
    int ct = 0;
    rep(i,0,n) {
        ct += (dp[i]<=tmi);
    }
    cout <<ct <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
        if(t) {
            cout <<"\n";
        }
    }
}