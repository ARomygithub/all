#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2e5;
int n;
int d[mxn];
ll ans[mxn], s[mxn];
vector<int> adj[mxn];

void dfs(int a=0, int p=-1) {
    s[a]=1;
    for(int b : adj[a]) {
        if(b==p) continue;
        d[b]=d[a]+1;
        dfs(b,a);
        s[a] +=s[b];
    }
}

void dfs2(int a=0, ll pd=0, int p=-1) {
    ans[a] =pd;
    for(int b : adj[a]) {
        if(b==p) continue;
        dfs2(b,pd-s[b]+(n-s[b]),a);
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
    ll sd=0;
    for(int i=0;i<n;i++) {
        sd +=d[i];
    }
    dfs2(0,sd,-1);
    for(int i=0;i<n;i++) {
        cout <<ans[i] <<" ";
    }
}
