#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
const ll mod=1e9+7;
int n,m, p[mxn],k;
vector<int> cs(mxn,1);
pii e[mxn];
int val[mxn], sum[mxn];
vector<pii> adj[mxn];
bool pick[mxn];

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

int find(int x) {
    return x^p[x]?p[x]=find(p[x]):x;
}

bool join(int x, int y) {
    if((x=find(x))==(y=find(y))) {
        return 0;
    }
    if (cs[x]>cs[y]) swap(x,y);
    cs[y]=cs[x]+cs[y];
    p[x]=y;
    return 1;
}

void dfs(int u, int par, int id) {
    sum[u] = val[u];
    if(id!=-1) pick[id]=1;
    for(auto [v,idx]: adj[u]) {
        if(v==par) continue;
        dfs(v,u,idx);
        sum[u] = (sum[u]+sum[v])%mod;
    }
    if(sum[u]==0 && id!=-1) pick[id]=0;
}

void solve() {
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        cin >>e[i].fi >>e[i].se; e[i].fi--, e[i].se--;
    }
    iota(p,p+n,0);
    cin >>k;
    for(int i=0;i<k;i++) {
        int a,b; cin >>a >>b; a--,b--;
        int x = 1+ (rng32()%(mod-1));
        val[a] = (val[a]+x)%mod;
        val[b] = (val[b]-x+mod)%mod;
    }
    for(int i=0;i<m;i++) {
        if(join(e[i].fi,e[i].se)) {
            adj[e[i].fi].push_back({e[i].se,i});
            adj[e[i].se].push_back({e[i].fi,i});
            pick[i] = 1;
            // cout <<i <<"\n";
        }
    }
    dfs(0,-1,-1);
    bool udh=0;
    for(int i=m-1;i>=0;i--) {
        if(pick[i]) {
            cout <<"1";
            udh = 1;
            // cout <<i <<"\n";
        } else {
            if(udh) cout <<"0";
        }
    }
    cout <<"0\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}