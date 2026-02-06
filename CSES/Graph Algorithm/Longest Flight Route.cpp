#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5;
int n,m,p[mxn], dp[mxn];
vector<int> adj[mxn];
bool vis[mxn], act[mxn];

void dfs(int u) {
    vis[u]=1;
    act[u]=1;
    dp[u]=u==n-1?1:-1e9;
    for(int a: adj[u]) {
        if(act[a]) {
            cout <<"IMPOSSIBLE";
            exit(0);
        }
        else {
            if(!vis[a]) {
                dfs(a);
            }
        }
        if(dp[a]+1>dp[u]) {
            dp[u]=dp[a]+1, p[u]=a;
        }
    }
    act[u]=0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int a,b; cin >>a >>b; a--, b--;
        adj[a].push_back(b);
    }
    dfs(0);
    if(dp[0]<0) {
        cout <<"IMPOSSIBLE";
    }
    else {
        int u=0;
        vector<int> ans;
        while(u!=n-1) {
            ans.push_back(u);
            u=p[u];
        }
        ans.push_back(u);
        cout <<ans.size() <<"\n";
        for(int a: ans) {
            cout <<a+1 <<" ";
        }
    }
}