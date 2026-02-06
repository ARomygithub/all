#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5, mod=1e9+7;
int n,m, who[mxn];
vector<int> adj[mxn], adj2[mxn], adj3[mxn], st, co;
bool vis[mxn];
ll x[mxn], y[mxn], dp[mxn];

void dfs1(int u) {
    vis[u]=1;
    for(int a: adj[u]) {
        if(!vis[a]) {
            dfs1(a);
        }
    }
    st.push_back(u);
}

void dfs2(int u, int rt) {
    vis[u]=0;
    who[u]=rt;
    for(int v: adj2[u]) {
        if(vis[v])
            dfs2(v,rt);
    }
    y[who[u]]+=x[u];
    co.push_back(u);
}

void dfs3(int u) {
    vis[u]=1;
    for(int a: adj3[u]) {
        if(!vis[a])
            dfs3(a);
        dp[u] = max(dp[u],dp[a]);
    }
    dp[u]+=y[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m;
    for(int i=0;i<n;i++)
        cin >>x[i];
    for(int i=0, a,b; i<m;i++) {
        cin >>a >>b; a--, b--;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }
    for(int i=0;i<n;i++) {
        if(!vis[i])
            dfs1(i);
    }
    for(int i=n-1;i>=0;i--) {
        if(vis[st[i]]) {
            dfs2(st[i],st[i]);
            co.clear();
        }
    }
    for(int i=0;i<n;i++) {
        for(int j : adj[i]) {
            if(who[i]!=who[j]) {
                adj3[who[i]].push_back(who[j]);
            }
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++) {
        if(who[i]==i&&!vis[i]) {
            dfs3(i), ans=max(dp[i],ans);
        }
    }
    cout <<ans;
}