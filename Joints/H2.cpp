#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
#define pll pair<ll,ll>

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5, mxm=5e3;
int n,m;
int d[mxn], anc[mxn][18];
vector<pii> adj[mxn];
ll dist[mxn];

void dfs(int a=0, int p=-1) {
    anc[a][0]=p;
    for(int i=1;i<18;i++) {
        anc[a][i]= ~anc[a][i-1]?anc[anc[a][i-1]][i-1]:-1;
    }
    for(auto [w,b] : adj[a]) {
        if(b==p) continue;
        d[b]=d[a]+1;
        dist[b] = dist[a]+w;
        dfs(b,a);
    }
}

int lca(int x, int k) {
    if(d[x]<d[k]) swap(x,k);
    for(int i=17;~i;i--) {
        if(d[x]-(1<<i)>=d[k]) x =anc[x][i];
    }
    if(x==k) return x;
    for(int i=17;~i;i--) {
        if(anc[x][i]^anc[k][i]) {
            x = anc[x][i]; k=anc[k][i];
        }
    }
    return anc[x][0];
}

ll distuv(int u, int v) {
    return dist[u]+dist[v]-dist[lca(u,v)];
}

void solve() {
    cin >>n >>m;
    for(int i=1;i<n;i++) {
        int u,v, w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    d[0] = 0;
    dist[0] = 0;
    vector<int> player(m);
    set<int> s;
    // priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=0;i<m;i++) {
        cin >>player[i]; player[i]--;
        s.insert(player[i]);
    }
    dfs();
    vector<int> lokasi;
    for(int lok : s) {
        lokasi.push_back(lok);
    }
    ll ans= 1e18;
    for(int i=0;i<n;i++) {
        ll temp = 0;
        for(int j=0;j<sz(lokasi);j++) {
            if(i==lokasi[j]) continue;
            temp += distuv(i,lokasi[j]);
        }
        min_self(ans, temp);
    }
    assert(ans!=1e18);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}