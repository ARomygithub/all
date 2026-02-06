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

const int mxn=5e5;
int n,t;

void solve() {
    cin >>n;
    vector adj(n, vi());
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    function<void(int,int)> dfs1,dfs2;
    int mn = n;
    vi dp(n,0), jauh(n,0);
    dfs1 = [&](int u, int p) -> void {
        jauh[u] = dp[u];
        for(int v: adj[u]) {
            if(v==p) continue;
            dp[v] = dp[u]+1;
            dfs1(v,u);
            max_self(jauh[u], jauh[v]);
        }
    };
    dfs1(0,-1);
    vi vd, vj;
    rep(i,0,n) {
        vd.push_back(dp[i]);
        vj.push_back(jauh[i]);
    }
    sort(all(vd));
    sort(all(vj));
    int ans = n;
    rep(i,0,n) {
        int temp = 0;
        auto it = lower_bound(all(vj),i) - vj.begin();
        temp += it;
        auto it2 = n - (upper_bound(all(vd),i) - vd.begin());
        temp += it2;
        min_self(ans, temp);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}