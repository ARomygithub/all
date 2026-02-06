#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5, mod=1e9+7;
int n,m, who[mxn];
vector<int> adj[mxn], adj2[mxn], st, co;
bool vis[mxn];

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
    co.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int a,b,c; cin >>a >>b; a--, b--;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }
    for(int i=0;i<n;i++) {
        if(!vis[i])
            dfs1(i);
    }
    vector<int> ans;
    for(int i=n-1;i>=0;i--) {
        if(vis[st[i]]) {
            dfs2(st[i],st[i]);
            ans.push_back(st[i]);
            co.clear();
        }
    }
    cout <<ans.size() <<"\n";
    map<int,int> mp;
    for(int i=0;i<ans.size();i++) {
        mp[ans[i]]=i;
    }
    for(int i=0;i<n;i++) {
        cout <<mp[who[i]]+1 <<" ";
    }
}