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
typedef pair<pii,pii> pipi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1<<18;
ll n,l;
ll t;
vector<pii> adj[mxn];
int x[mxn];

void solve() {
    cin >>n >>l >>t;
    rep(i,0,l) {
        int u,v;cin >>u >>v; u--,v--;
        adj[v].push_back({i,u});
    }
    rep(i,0,n) {
        cin >>x[i];
    }
    priority_queue<pipi,vector<pipi>,greater<pipi>> pq;
    vector dp(n,vector<pii>(8,{2e9,-1}));
    rep(i,0,n) {
        rep(j,0,8) {
            if((x[i]>>j)&1) {
                dp[i][j] = {0,1e9};
                pq.push({dp[i][j],{i,j}});
            }
        }
    }
    pll temp = {(t+l-1)/l, ((t-1)%l)};
    pii tlast ={(int)min(temp.fi,(ll)(1e9)), temp.se};
    while(sz(pq)) {
        auto [dpij, ij] = pq.top(); pq.pop();
        auto [ti, pos] = dpij;
        auto [i, j] = ij;
        if(dp[i][j]<dpij) continue;
        for(auto [posi,v]: adj[i]) {
            int tnext = ti+(posi<=pos);
            if(dp[v][j] > make_pair(tnext,posi) && make_pair(tnext,posi)<=tlast) {
                dp[v][j] = {tnext,posi};
                pq.push({dp[v][j],{v,j}});
            }
        }
    }
    vector<int> ans(n,0);
    rep(i,0,n) {
        rep(j,0,8) {
            if(dp[i][j].fi<=tlast.fi) {
                ans[i] += 1<<j;
            }
        }
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}