#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5;
int n,m,p[mxn];
ll dp[mxn];
vector<ar<int,2>> adj[mxn];
bool vis[mxn], act[mxn];

void dfs(int u) {
    vis[u]=1;
    act[u]=1;
    dp[u]=(u==(n-1)?0:-1e9);
    for(auto a: adj[u]) {
        if(act[a[1]]) {
            cout <<"IMPOSSIBLE";
            exit(0);
        }
        else {
            if(!vis[a[1]]) {
                dfs(a[1]);
            }
        }
        if(dp[a[1]]+(ll)a[0]>dp[u]) {
            dp[u]=dp[a[1]]+(ll)a[0], p[u]=a[1];
        }
    }
    act[u]=0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int a,b,c; cin >>a >>b >>c; a--, b--;
        adj[a].push_back({c,b});
    }
    dfs(0);
    if(n==1) {
        cout <<"-1";
        return 0;
    }
    if(dp[0]<=0) {
        cout <<"-1";
    }
    else {
        cout <<dp[0];
    }
}