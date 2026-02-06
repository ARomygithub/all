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
const ll mod = 1e9+7;
int n,m;
vector<pii> adj[mxn*13];

void solve() {
    cin >>n >>m;
    int id = n;
    auto add = [&](int i, int u, int v) -> void {
        int nx = v;
        while(i>=10) {
            adj[id].push_back({i%10,nx});
            i /= 10;
            nx = id; id++;
        }
        adj[u].push_back({i,nx});
    };
    rep(i,1,m+1) {
        int u,v; cin >>u >>v; u--,v--;
        add(i,u,v);
        add(i,v,u);
    }
    vector<ll> dp(id,1e18);
    queue<int> q;
    dp[0] = 0;
    q.push(0);
    while(sz(q)) {
        vi upd;
        upd.push_back(q.front()); q.pop();
        while(sz(q) && dp[q.front()]==dp[upd.back()]) {
            upd.push_back(q.front()); q.pop();
        }
        ll val = dp[upd.back()];
        vector<pii> vv;
        for(auto u : upd) {
            for(auto [k,v]: adj[u]) {
                vv.push_back({k,v});
            }
        }
        sort(all(vv));
        for(auto [k,v]: vv) {
            if(dp[v]==1e18) {
                dp[v] = (val*10%mod + k)%mod;
                q.push(v);
            }
        }
    }
    rep(i,1,n) {
        cout <<dp[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}