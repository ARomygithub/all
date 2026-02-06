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
int n,m,k;
ll t;
vector<pii> adj[mxn];
using pli = pair<ll,int>;

void solve() {
    cin >>n >>m >>k >>t;
    vector<bool> st(n,1);
    rep(i,0,k) {
        int pi; cin >>pi; pi--;
        st[pi] = 0;
    }
    rep(i,0,m) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    vector<ll> dp(n,2e18);
    priority_queue<pli,vector<pli>,greater<pli>> pq;
    rep(i,0,n) {
        if(st[i]) {
            dp[i] = 0;
            pq.push({0ll,i});
        }
    }
    while(sz(pq)) {
        auto [d,u] = pq.top(); pq.pop();
        if(dp[u]<d) continue;
        for(auto [w,v]: adj[u]) {
            if(dp[v] > dp[u]+w) {
                dp[v] = d+w;
                pq.push({dp[v],v});
            }
        }
    }
    rep(i,0,n) {
        if(dp[i]<=t) {
            cout <<"0";
        } else {
            cout <<"1";
        }
    }
    cout <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
        solve();
}