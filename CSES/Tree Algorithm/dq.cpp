#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2e5;
int n,q;
int d[mxn], anc[mxn][18];
vector<int> adj[mxn];

void dfs(int a=0, int p=-1) {
    anc[a][0]=p;
    for(int i=1;i<18;i++) {
        anc[a][i]= ~anc[a][i-1]?anc[anc[a][i-1]][i-1]:-1;
    }
    for(int b : adj[a]) {
        if(b==p) continue;
        d[b]=d[a]+1;
        dfs(b,a);
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
    while(q--) {
        int x,k; cin >>x >>k; x--, k--;
        cout <<d[x]+d[k]-2*d[lca(x,k)] <<"\n";
    }
}
