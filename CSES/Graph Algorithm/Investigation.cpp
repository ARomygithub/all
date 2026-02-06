#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5, mod=1e9+7;
int n,m,p[mxn], dp[mxn];
vector<int> adj[mxn];
vector<ar<ll,2>> adj2[mxn];
ll d[mxn];
bool vis[mxn];

void dfs(int u) {
    dp[u]=u==n-1?1:0;
    vis[u]=1;
    for(int a: adj[u]) {
        if(!vis[a]) {
            dfs(a);
        }
        dp[u]=(dp[u]+dp[a])%mod;
    }
}

void dfs2(int u) {
    dp[u]=u==n-1?1:1e9;
    vis[u]=1;
    for(int a: adj[u]) {
        if(!vis[a]) {
            dfs2(a);
        }
        if(dp[u]>1+dp[a]) {
            dp[u]=1+dp[a];
        }
    }
}

void dfs3(int u) {
    dp[u]=u==n-1?1:-1e9;
    vis[u]=1;
    for(int a: adj[u]) {
        if(!vis[a]) {
            dfs3(a);
        }
        if(dp[u]<1+dp[a]) {
            dp[u]=1+dp[a];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int a,b,c; cin >>a >>b >>c; a--, b--;
        adj2[a].push_back({c,b});
    }
    memset(d, 0x3f, sizeof(d));
    d[0]=0;
    priority_queue<ar<ll,2>,vector<ar<ll,2>>,greater<ar<ll,2>>> pq;
    pq.push({0,0});
    while(pq.size()) {
        ar<ll,2> u=pq.top(); pq.pop();
        if(u[0]>d[u[1]])
            continue;
        for(ar<ll,2> v : adj2[u[1]]) {
            if(u[0]+v[0]<d[v[1]]) {
                d[v[1]]=u[0]+v[0];
                pq.push({d[v[1]],v[1]});
            }
        }
    }
    for(int i=0;i<n;i++)
        for(ar<ll,2> j : adj2[i]) {
            if(j[0]+d[i]==d[j[1]]) {
                adj[i].push_back(j[1]);
            }
        }
    dfs(0);
    cout <<d[n-1] <<" " <<dp[0]; //<< " " <<dp[1] <<" " <<dp[2] <<" " <<dp[3];
    memset(vis,0,n);
    dfs2(0);
    cout <<" " <<dp[0]-1;
    memset(vis,0,n);
    dfs3(0);
    cout <<" " <<dp[0]-1;
}