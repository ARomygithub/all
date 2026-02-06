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
const ll mod=998244353;
int n,m;
vector<int> adj[mxn];
bool vis[mxn];
bool isTree = 1;
vector<ll> val;
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
ll pw1 = 1 + (rng64()%(mod-1)), pw2 = 1 + (rng64()%(mod-1));
ll vl[mxn];

void dfs(int u, int p=-1) {
    vis[u] = 1;
    for(int v: adj[u]) {
        if(v==p) continue;
        if(vis[v]) {
            isTree = 0;
            return;
        } else {
            dfs(v,u);
        }
        if(!isTree) return;
    }
}

void dfs2(int u, int p=-1) {
    for(int v: adj[u]) {
        if(v==p) continue;
        dfs2(v,u);
        vl[u] = (vl[u] + vl[v]*pw1%mod)%mod;
    }
    if(sz(adj[u])==1) {
        vl[u] = (vl[u]+1)%mod;
    }
}

void dfs3(int u, int p=-1) {
    for(int v: adj[u]) {
        if(v==p) continue;
        ll temp = (vl[u]-vl[v]*pw1%mod + mod)%mod;
        temp = (temp*pw1)%mod;
        vl[v] = (vl[v] + temp)%mod;
        dfs3(v,u);
    }
    val.push_back(vl[u]);
}

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v; cin >>u >>v;u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    map<ll,int> mp;
    rep(i,0,n) {
        if(!vis[i]) {
            isTree = 1;
            dfs(i,-1);
            if(!isTree) continue;            
            val.clear();
            dfs2(i,-1);
            dfs3(i,-1);
            sort(val.begin(),val.end());
            ll vali = 0;
            rep(j,0,sz(val)) {
                vali = (vali*pw2%mod + val[j])%mod;
            }
            mp[vali]++;
        }
    }
    ll ans = 0;
    for(auto [k,v]: mp) {
        ans += 1ll*v*(v-1)/2;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}