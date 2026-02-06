#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2e5;
int n, d[mxn], ans;
vector<int> adj[mxn];

void dfs(int a=0, int p=-1) {
    for(int b : adj[a]) {
        if(b==p) continue;
        dfs(b,a);
        ans = max(ans, d[a]+d[b]+1);
        d[a] = max(d[a],d[b]+1);
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
    cout <<ans;
}
