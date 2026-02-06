#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 1e5;
int n, m;
vector<int> adj[mxn+1], ans;
bool vis[mxn+1];

void dfs(int d) {
    vis[d]=true;
    for(auto e : adj[d]) {
        if(!vis[e])
            dfs(e);
    }
}
int main() {
    cin >>n >>m;
    for(int i=0; i<m; i++) {
        int a,b;
        cin >>a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis,false,n+1);
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            ans.push_back(i);
            dfs(i);
        }
    }
    cout <<ans.size()-1 <<"\n";
    if(ans.size()>1)
    for(auto it=++ans.begin(), l=ans.begin(); it!=ans.end(); it++) {
        cout << *l <<" " <<*it <<"\n";
        ++l;
    }
}
