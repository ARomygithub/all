#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2e5;
int n,m, c[mxn], ans[mxn];
int d[mxn], s[mxn], anc[mxn][18];
vector<int> adj[mxn];

void dfs(int a=0, int p=-1) {
    s[a]=1;
    anc[a][0]=p;
    for(int i=1;i<18;i++) {
        anc[a][i]= ~anc[a][i-1]?anc[anc[a][i-1]][i-1]:-1;
    }
    for(int b : adj[a]) {
        if(b==p) continue;
        d[b]=d[a]+1;
        dfs(b,a);
        s[a] +=s[b];
    }
}

int lca(int x, int k) {
    if(d[x]<d[k]) swap(x,k);
    for(int i=17;~i;i--) {
        if(d[x]-(1<<i)>=d[k]) x =anc[x][i];
    }
    if(x==k) return x;
    for(int i=17;~i;i--) {
        if(anc[x][i]^anc[k][i]) {
            x = anc[x][i]; k=anc[k][i];
        }
    }
    return anc[x][0];
}

void dfs2(int a=0, int p=-1) {
    for(int b : adj[a]) {
        if(b^p) {
            dfs2(b,a);
            c[a] +=c[b];
        }
    }
    ans[a]=c[a];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    cin >>n >>m;
    for(int i=1;i<n;i++) {
        int a,b; cin >>a >>b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    for(int i=0;i<m;i++) {
        int a,b; cin >>a >>b; a--, b--;
        ++c[a], ++c[b];
        int d= lca(a,b);
        -- c[d];
        if(d) --c[anc[d][0]];
    }
    dfs2();
    for(int i=0;i<n;i++) {
        cout <<ans[i] <<" ";
    }
}
