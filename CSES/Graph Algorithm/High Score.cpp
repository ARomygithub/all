#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2500;
int n,m;
ll ans[mxn];
vector<ar<ll,2>> adj[mxn];
vector<int> adj2[mxn];
ll d[mxn];
bool vis[mxn], vis2[mxn];

void dfs(int u) {
    vis[u]=1;
    for(int v: adj2[u]) {
        if(!vis[v])
            dfs(v);
    }
}

void dfs2(int u) {
    vis2[u]=1;
    for(ar<ll,2> v: adj[u]) {
        if(!vis2[v[1]])
            dfs2(v[1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int a,b,c;
        cin >>a >>b >>c; --a, --b;
        adj[a].push_back({c,b});
        adj2[b].push_back(a);
    }
    dfs(n-1);
    dfs2(0);
    memset(d,0xc0,sizeof(d));
    d[0]=0;
    for(int i=0;i<5*n;i++) {
        bool ch=0;
        for(int j=0;j<n;j++) {
            for(ar<ll,2> a: adj[j]) {
                if(d[j]+a[0]>d[a[1]]) {
                    if(vis[a[1]]&&vis2[a[1]])
                        ch=1;
                    d[a[1]]=d[j]+a[0];
                }
            }
        }
        if(i>=n-1&&ch) {
            cout <<"-1";
            return 0;
        }
    }
    cout << d[n-1];
}   