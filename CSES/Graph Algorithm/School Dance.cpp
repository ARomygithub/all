#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=500;
int n,m,k, mt[mxn];
vector<int> adj[mxn];
bool vis[mxn];

bool dfs(int u) {
    vis[u]=1;
    for(int v1 : adj[u]) {
        if(mt[v1]<0||(!vis[mt[v1]]&&dfs(mt[v1]))) {
            mt[v1]=u;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m >>k;
    for(int i=0;i<k;i++) {
        int a,b; cin >>a >>b; a--, b--;
        adj[a].push_back(b);
    }
    int f=0;
    memset(mt,-1,4*m);
    for(int i=0;i<n;i++) {
        memset(vis,0,n);
        f+=dfs(i);
    }
    cout <<f <<"\n";
    for(int i=0;i<m;i++) {
        if(~mt[i]) {
            cout <<mt[i]+1 <<" " <<i+1 <<"\n";
        }
    }
}