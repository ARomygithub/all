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
int n,t;
vector<int> adj[mxn];
int dp[mxn];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

void dfs(int u=0, int p=-1) {
    for(auto v: adj[u]) {
        if(v==p) continue;
        dfs(v,u);
        max_self(dp[u],dp[v]);
    }
    dp[u]++;
}

void solve() {
    cin >>n;
    for(int i=1;i<n;i++) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    ll ans= fastexpo(2ll,n-1);
    ll temp=0;
    for(int i=0;i<n;i++) {
        temp +=dp[i];
    }
    temp %=mod;
    ans = ans*temp%mod;
    cout <<ans <<"\n";
    for(int i=0;i<n;i++) {
        adj[i].clear();
        dp[i]=0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}