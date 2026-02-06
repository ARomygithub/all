#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5, mod=1e9+7;
int n,m,p[mxn], ans[mxn];
vector<int> adj[mxn];
bool vis[mxn];

void dfs(int u) {
    vis[u]=1;
    for(int a: adj[u]) {
        if(a==n-1)
            ans[u]=(ans[u]+1)%mod;
        if(!vis[a]) {
            dfs(a);
        }
        ans[u]=(ans[u]+ans[a])%mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int a,b; cin >>a >>b; a--, b--;
        if(a!=n-1)
            adj[a].push_back(b);
    }
    dfs(0);
    cout <<ans[0];
}