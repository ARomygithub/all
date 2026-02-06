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
int n;
int a[mxn];
vector<int> adj[mxn];
map<int,int> mp;

void dfs(int u, int p, int val) {
    for(int v: adj[u]) {
        if(v==p) continue;
        mp[val^a[v]]++;
        dfs(v,u,val^a[v]);
    }
}

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    for(int i=1;i<n;i++) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1,a[0]);
    ll ans=0;
    if(mp.count(0)) {
        ans = mp[0];
    }
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