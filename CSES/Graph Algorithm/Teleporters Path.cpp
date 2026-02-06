#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5, mxm=2e5, mod=1e9+7;
int n,m, eu[mxm], ev[mxm];
vector<int> adj[mxn], adj2[mxn], ans;
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
        adj2[ev[i]].push_back(i);
    }
    for(int i=1;i<n-1;i++) {
        if(adj[i].size()!=adj2[i].size()) {
            cout <<"IMPOSSIBLE";
            return 0;
        }
    }
    if(adj[0].size()!=adj2[0].size()+1 || adj[n-1].size()+1!=adj2[n-1].size()) {
        cout <<"IMPOSSIBLE";
        return 0;
    }
    ans.push_back(n-1);
    dfs();
    if(ans.size()^m+1) {
        cout <<"IMPOSSIBLE";
    } else {
        reverse(ans.begin(),ans.end());
        for(int a: ans)
            cout <<a+1 <<" ";
    }
}