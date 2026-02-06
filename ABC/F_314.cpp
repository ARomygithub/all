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

const int mxn=2e5;
const ll mod = 998244353;
int n;
int p[mxn*2-1], cs[mxn*2-1];
ll val[mxn*2-1];
pii lr[mxn*2-1];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = ret*a%mod;
        a = a*a%mod;
        b >>=1;
    }
    return ret;
}

ll inv(ll a) {
    return fastexpo(a,mod-2);
}

int find(int x) {
    return x==p[x]?x:p[x]=find(p[x]);
}

void join(int x, int y, int par) {
    x = find(x), y = find(y);
    p[x] = par, p[y] = par;
    p[par] = par;
    cs[par] = cs[x]+cs[y];
    lr[par] = {x,y};
    val[x] = cs[x]*inv(cs[par])%mod;
    val[y] = cs[y]*inv(cs[par])%mod;
}

void dfs(int u) {
    if(u<=n-1) return;
    val[lr[u].fi] = (val[lr[u].fi] + val[u])%mod;
    val[lr[u].se] = (val[lr[u].se] + val[u])%mod;
    dfs(lr[u].fi);
    dfs(lr[u].se);
}

void solve() {
    cin >>n;
    int id = n;
    iota(p,p+n,0);
    fill(cs,cs+n,1);
    rep(i,1,n) {
        int par = id++;
        int pi,qi; cin >>pi >>qi; pi--,qi--;
        join(pi,qi,par);
    }
    dfs(n*2-2);
    rep(i,0,n) {
        cout <<val[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}