#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5;
int n,m,p[mxn];
vector<int> adj[mxn], ans;
bool vis[mxn], act[mxn];

void dfs(int u) {
    vis[u]=1;
    act[u]=1;
    for(int a: adj[u]) {
        if(act[a]) {
            cout <<"IMPOSSIBLE";
            exit(0);
        }
        else {
            if(!vis[a]) {
                p[a]=u;
                dfs(a);
            }
        }
    }
    act[u]=0;
    ans.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int a,b; cin >>a >>b; a--, b--;
        adj[a].push_back(b);
    }
    for(int i=0;i<n;i++) {
        if(!vis[i])
            dfs(i);
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<n;i++) {
        cout <<ans[i]+1 <<" ";
    }
}