#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5, mxm=2e5;
int n,m,p[mxn];
vector<int> adj[mxn], ans;
bool vis[mxn];

void dfs(int u, int pu=-1) {
    vis[u]=1;
    p[u]=pu;
    for(int a : adj[u]) {
        if(a==pu) {
            continue;
        }
        else if(vis[a]) {
            int u2=u;
            while(u^a) {
                ans.push_back(u);
                u=p[u];
            }
            ans.push_back(a);
            ans.push_back(u2);
            cout <<ans.size() <<"\n";
            for(int i: ans) {
                cout <<i+1 <<" ";
            }
            exit(0);
        }
        else {
            dfs(a,u);
        }
    }
}

int main() {
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int a,b;
        cin >>a >>b; a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    cout <<"IMPOSSIBLE";
}