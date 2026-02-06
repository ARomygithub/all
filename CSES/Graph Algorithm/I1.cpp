
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2e5;
int n,q, p[mxn], p1[mxn];
vector<int> cs(mxn,1);
vector<ar<int,2>> adj[mxn];
ar<int,3> e[mxn];

int find(int x) {
    return x^p[x]?p[x]=find(p[x]):x;
}

bool join(int x, int y) {
    if((x=find(x))==(y=find(y))) {
        return 0;
    }
    if (cs[x]>cs[y]) swap(x,y);
    cs[y]=cs[x]+cs[y];
    p[x]=y;
    return 1;
    //update cs juga
}

void dfs(int s, int e) {
    for(auto u: adj[s]) {
        if(u[1]==e) continue;
        p1[u[1]]=s;
        dfs(u[1],s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>q;
    for(int i=0;i<n-1;i++) {
       int a,b,c; cin >>a >>b >>c; a--, b--;
       if(a>b) swap(a,b);
       adj[a].push_back({c,b});
    }
    iota(p,p+n,0);
    for(int i=0;i<q;i++) {
        int a,b; cin >>a >>b; a--, b--;
        iota(p1,p1+n,0);
        dfs(a,a);
        int d=b, c=p1[b];
        ll ans=0;
        while(find(a)!=find(b)) {
            if(join(c,d)) {
                for(auto u : adj[c]) {
                    if(u[1]==d) ans+=u[0];
                }
            }
            d = p1[d]; c=p1[c];
        }
        cout <<ans <<"\n";
    }
}