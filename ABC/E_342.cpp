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
typedef pair<pipi,int> pipii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
ll n,m;
vector<pipii> adj[mxn];

ll getLast(int l, int d, int k, int c, ll t) {
    if(l+c>t) {
        return -1;
    }
    if(1ll*l+1ll*(k-1)*d+c <=t) {
        return 1ll*l+1ll*(k-1)*d;
    }
    ll temp = t-l-c;
    ll ret = 1ll*l + (temp - (temp%d));
    return ret;
}

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int l,d,k,c,a,b; cin >>l >>d >>k >>c >>a >>b;
        a--,b--;
        adj[b].push_back({{{l,d},{k,c}},a});
    }
    vector<ll> dp(n,-1);
    priority_queue<pll> pq;
    dp[n-1] = 2e18;
    pq.push({dp[n-1],n-1});
    while(sz(pq)) {
        auto [t,u] = pq.top(); pq.pop();
        if(dp[u]>t) continue;
        for( auto [ldkc,v]: adj[u]) {
            auto [ld,kc] = ldkc;
            auto [l,d] = ld;
            auto [k,c] = kc;
            ll ts = getLast(l,d,k,c,t);
            if(ts>dp[v]) {
                dp[v] = ts;
                pq.push({ts,v});
            }
        }
    }
    rep(i,0,n-1) {
        if(dp[i]==-1) {
            cout <<"Unreachable\n";
        } else {
            cout <<dp[i] <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}