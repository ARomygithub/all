#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2e5;
int n,q;
int d[mxn], s[mxn];
vector<int> adj[mxn], v[mxn];

void dfs(int a=0, int p=-1) {
    s[a]=1;
    for(int b : adj[a]) {
        if(b==p) continue;
        d[b]=d[a]+1;
        dfs(b,a);
        s[a] +=s[b];
        v[a].push_back(s[b]);
    }
    v[a].push_back(n-s[a]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    cin >>n >>q;
    for(int i=1;i<n;i++) {
        int a,b; cin >>a >>b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    for(int i=0;i<n;i++) {
        ll ans=0;
        for(int a : v[i]) {
            ans += 1ll*a*(n-1-a);
        }
        ans /=2;
        ans +=n-1;
        cout <<ans <<" ";
    }
}
