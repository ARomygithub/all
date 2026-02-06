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

const int mxn=5e3;
int n,m,t;
ll w[mxn];
vi adj[mxn];
using plli = pair<pll,int>;

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>w[i];
    }
    rep(j,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector dp(n, set<pll>());
    priority_queue<plli,vector<plli>,greater<plli>> pq;
    dp[0].insert({0ll,0ll});
    pq.push({{0ll,0ll},0});
    while(sz(pq)) {
        auto [val,u] = pq.top(); pq.pop();
        if(!dp[u].count({val.se,val.fi})) continue;
        ll cur = val.fi+val.se+w[u];
        ll udh = val.se+w[u];
        for(int v: adj[u]) {
            auto it = dp[v].upper_bound({udh,-1ll});
            if(it != dp[v].begin()) {
                it--;
                auto [udhp, curp] = *it;
                if(curp<= cur) {
                    continue;
                }
                it++;
            }
            vector<pll> toer;
            while(it != dp[v].end()) {
                if(it->se >=cur) {
                    toer.push_back(*it);
                    it++;
                } else {
                    break;
                }
            }
            for(auto eri: toer) {
                dp[v].erase(eri);
            }
            dp[v].insert({udh,cur});
            pq.push({{cur,udh},v});
        }
    }
    rep(i,0,n) {
        auto it = --dp[i].end();
        cout <<(it->se) <<"\n";
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