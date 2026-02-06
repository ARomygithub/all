#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 1e5;
int n, m, p[mxn];
vector<int> ans, adj[mxn];
bool vis[mxn];

int main() {
    cin >>n >>m;
    for(int i=0; i<m; i++) {
        int a,b;
        cin >>a >>b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> qu;
    qu.push(0);
    vis[0]=true;
    while(!qu.empty()) {
        int u=qu.front();
        qu.pop();
        for(int t : adj[u]) {
            if(!vis[t]) {
                p[t]=u;
                vis[t]=true;
                qu.push(t);
            }
        }
    }
    if(vis[n-1]) {
        int k=n-1;
        while(k!=0) {
            ans.push_back(k);
            k=p[k];
        }
        ans.push_back(k);
        cout <<ans.size() <<"\n";
        for(auto it=--ans.end(); it>=ans.begin(); it--) {
            cout <<*it+1 <<" ";
        }
    }
    else
        cout <<"IMPOSSIBLE\n";
}
