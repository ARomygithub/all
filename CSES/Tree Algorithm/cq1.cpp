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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    cin >>n >>q;
    for(int i=1;i<n;i++) {
        int p; cin >>p; p--;
        adj[p].push_back(i);
    }
    dfs();
    while(q--) {
        int x,k; cin >>x >>k; x--;
        if(d[x]<k) {
            cout <<"-1\n";
        } else {
            for(int i=17;~i;i--) {
                if(k>>i &1) x = anc[x][i];
            }
            cout <<x+1 <<"\n";
        }
    }
}