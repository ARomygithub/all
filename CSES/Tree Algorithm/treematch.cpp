#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2e5;
int n, dp0[mxn], dp1[mxn];
vector<int> adj[mxn];

void dfs(int a=0, int p=-1) {
    for(int b : adj[a]) {
        if(b==p) continue;
        dfs(b,a);
        dp1[a] = max(dp1[a]+max(dp0[b],dp1[b]), dp0[a]+dp0[b]+1);
        dp0[a] += max(dp0[b],dp1[b]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    cin >>n;
    for(int i=1;i<n;i++) {
        int a,b; cin >>a >>b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    cout <<max(dp0[0],dp1[0]);
}
