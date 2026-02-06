#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=500, mxm=1e3, mod=1e9+7;
int n,m, d[mxn], p[mxn];
vector<int> adj[mxn];

struct edge{
    int u,v,rev,cap;
} e[2*mxm];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int a,b,c; cin >>a >>b >>c; --a, --b;
        e[2*i]={a,b,2*i+1,c};
        e[2*i+1]={b,a,2*i,0};
        adj[a].push_back(2*i);
        adj[b].push_back(2*i+1);
    }
    ll f=0;
    while(1) {
        memset(d,0x3f,sizeof(d));
        d[0]=0;
        queue<int> qu;
        qu.push(0);
        while(qu.size()) {
            int u=qu.front(); qu.pop();
            for(int i : adj[u]) {
                if(e[i].cap&&d[e[i].v]>1e9) {
                    d[e[i].v]=d[u]+1;
                    p[e[i].v]=i;
                    qu.push(e[i].v);
                }
            }
        }
        if(d[n-1]>1e9)
            break;
        int mf=1e9, u=n-1;
        while(u) {
            mf=min(mf,e[p[u]].cap);
            u=e[p[u]].u;
        }
        f+=mf;
        u=n-1;
        while(u) {
            e[p[u]].cap-=mf;
            e[e[p[u]].rev].cap+=mf;
            u=e[p[u]].u;
        }
    }
    cout <<f;
}