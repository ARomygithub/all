#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5, mxm=2e5;
int n,m,p[mxn];
vector<int> adj[mxn];
bool vis[mxn], act[mxn];

void dfs(int u) {
    vis[u]=1;
    act[u]=1;
    for(int a : adj[u]) {
        if(act[a]) {
            vector<int> ans= {a};
            while(u^a) {
                ans.push_back(u);
                u=p[u];
            }
            ans.push_back(a);
            reverse(ans.begin(),ans.end());
            cout <<ans.size() <<"\n";
            for(int i: ans) {
                cout <<i+1 <<" ";
            }
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
}

int main() {
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int a,b;
        cin >>a >>b; a--,b--;
        adj[a].push_back(b);
    }
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    cout <<"IMPOSSIBLE";
}