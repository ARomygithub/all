#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5, mxm=2e5, mod=1e9+7;
int n,m, eu[mxm], ev[mxm];
vector<int> adj[mxn], ans;
bool used[mxm];

void dfs(int u=0) {
    while(adj[u].size()) {
        int e=adj[u].back(); adj[u].pop_back();
        if(used[e])
            continue;
        used[e]=1;
        dfs(eu[e]^ev[e]^u);
        ans.push_back(u); // u nya dipake, dipush terakhir2
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        cin >>eu[i] >>ev[i]; eu[i]--, ev[i]--;
        adj[eu[i]].push_back(i);
        adj[ev[i]].push_back(i);
    }
    for(int i=0;i<n;i++) {
        if(adj[i].size()&1) {
            cout <<"IMPOSSIBLE";
            return 0;
        }
    }
    ans.push_back(0);
    dfs();
    if(ans.size()^m+1) {
        cout <<"IMPOSSIBLE";
    } else
        for(int a: ans)
            cout <<a+1 <<" ";
}