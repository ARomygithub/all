#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2e5, mod=1e9+7;
int n,q, t[mxn], rt[mxn], rp[mxn], d[mxn], de[mxn], ds[mxn], dt, cr[mxn], cs[mxn];
vector<int> adj[mxn], cyc;
bool vis[mxn];

void dfs1(int u) {
    ds[u]=dt++;
    for(int v: adj[u]) {
        if(rt[v]^v) {
            d[v]=d[u]+1;
            rt[v]=rt[u];
            cr[v]=cr[u];
            dfs1(v);
        }
    }
    de[u]=dt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>q;
    memset(rt,-1,4*n);
    for(int i=0;i<n;i++) {
        cin >>t[i]; t[i]--;
        adj[t[i]].push_back(i);
    }
    for(int i=0;i<n;i++) {
        if(~rt[i])
            continue;
        int u=i;
        while(!vis[u]) {
            vis[u]=1;
            u=t[u];
        } 
        while(!cyc.size()||u^cyc[0]) {
            rp[u]=cyc.size();
            cyc.push_back(u);
            rt[u]=u; 
            cr[u]=i;
            u=t[u];
        }
        for(int ci: cyc) {
            dt=0, dfs1(ci), cs[ci]=cyc.size();
        }
        cyc.clear();
    }

    while(q--) {
        int a,b; cin >>a >>b; a--, b--;
        int ans=-1;
        if(cr[a]==cr[b]) {
            if(rt[b]==b) {
                ans=d[a];
                a=rt[a];
                ans+=(rp[b]-rp[a]+cs[a])%cs[a];
            }
            else {
                if(rt[a]==rt[b]&& ds[b]<=ds[a]&& ds[a]<de[b]) {
                    ans=d[a]-d[b];
                }
            }
        }
        cout <<ans <<"\n";
    }
}