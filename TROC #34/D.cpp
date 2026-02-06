#include <bits/stdc++.h>
using namespace std;

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

const int mxn=1e5;
int n,k;
vector<int> adj[mxn];
int a[mxn], ct[mxn],d[mxn];
ll ans=0;
int center=-1;

void dfs0(int u, int p=-1) {
    for(int v: adj[u]) {
        if(v==p) continue;
        dfs0(v,u);
        ct[u] +=ct[v];
    }
}

void dfs1(int u, int p=-1) {
    int vmax=-1,mx=0;
    for(int v: adj[u]) {
        if(v==p) continue;
        if(ct[v]>mx) {
            vmax = v;
            mx = ct[v];
        }
    }
    if(mx*2>k) {
        dfs1(vmax,u);
    } else {
        center = u;
    }
}

void dfs2(int u, int p=-1) {
    for(int v: adj[u]) {
        if(v==p) continue;
        d[v] = d[u]+1;
        dfs2(v,u);
    }
}

void solve() {
    cin >>n;
    for(int i=1;i<n;i++) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >>k;
    vector<int> vk(k);
    for(int i=0;i<k;i++) {
        int b; cin >>a[i] >>b; b--;
        ct[b]++;
        vk[i] = b;
    }
    sort(a,a+k);
    for(int i=0;i<k;i++) {
        ans +=abs(a[k/2]-a[i]);
    }
    dfs0(0);
    dfs1(0);
    dfs2(center);
    for(auto vki : vk) {
        ans +=d[vki];
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}