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

const int mxn=3000,mxa=3000;
const ll mod=998244353;
int n;
ll fct[mxa+1];
vector<int> adj[mxn];

pll dfs(int u, int p=-1) {
    vector<ll> res = {1};
    for(int v: adj[u]) {
        if(v==p) continue;
        auto [r, c] = dfs(v,u);
        vector<ll> res_new(sz(res)+1);
        rep(i,0,sz(res_new)) {
            ll temp = 0;
            if(i+1<sz(res_new)) {
                temp = (temp + res[i]*r%mod)%mod;
            }
            if(i>0) {
                temp = (temp + res[i-1]*c%mod)%mod;
            }
            res_new[i] = temp;
        }
        res.swap(res_new);
    }
    ll s=0, t=0;
    rep(i,0,sz(res)) {
        s = (s + res[i]*fct[i]%mod)%mod;
        t = (t + res[i]*fct[i]%mod*i%mod)%mod;
    }
    return {s,(s+t)%mod};
}

void solve() {
    cin >>n;
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout <<dfs(0,-1).fi <<"\n";
}

void init() {
    fct[0] = 1;
    rep(i,1,mxa+1) {
        fct[i] = fct[i-1]*i%mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}