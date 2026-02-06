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
int n,m;
using piii = pair<pii,pii>;
vector<piii> adj[mxn];
using pli = pair<ll,int>;

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v,t,c; cin >>u >>v >>c >>t; u--,v--;
        adj[u].push_back({{0,c},{t,v}});
        adj[v].push_back({{1,c},{t,u}});
    }
    int x,y; cin >>x >>y; x--,y--;
    vector<ll> dp(n, 1e18);
    dp[x] = 0;
    priority_queue<pli,vector<pli>,greater<pli>> pq;
    pq.push({0,x});
    while(sz(pq)) {
        auto [d,u] = pq.top(); pq.pop();
        if(dp[u]<d) continue;
        for(auto [rc,tv]: adj[u]) {
            auto [r,c] = rc;
            auto [t,v] = tv;
            ll dn = d;
            if(((dn/t)%2) != r) {
                dn += t-(dn%t);
            }
            if(dn + c < dp[v]) {
                dp[v] = dn+c;
                pq.push({dp[v],v});
            }
        }
    }
    if(dp[y]==1e18) {
        cout <<"-1\n";
    } else {
        cout <<dp[y] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}