#include <bits/stdc++.h>
using namespace std;

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef pair<int,pii> ipii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,m;
vector<pii> adj[mxn];
int p[mxn*2],cs[mxn*2];

int find(int x) {
    return x==p[x]?x:(p[x]=find(p[x]));
}

bool join(int x, int y) {
    if((x=find(x))==(y=find(y))) {
        return false;
    }
    if(cs[x]>cs[y]) swap(x,y);
    cs[y] +=cs[x];
    p[x] = y;
    return true;
}

void solve() {
    cin >>n >>m;
    vector<ipii> edges;
    for(int i=0;i<m;i++) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
        edges.push_back({w,{u,v}});
    }
    for(int i=0;i<n;i++) {
        sort(adj[i].begin(),adj[i].end());
    }
    ll ans=1e18;
    for(int i=0;i<n;i++) {
        if(sz(adj[i])>=2) {
            min_self(ans,1ll*adj[i][0].fi+adj[i][1].fi);
        }
    }
    sort(edges.begin(),edges.end());
    iota(p,p+n*2,0);
    fill(cs,cs+n*2,1);
    for(auto [w,uv]: edges) {
        auto [u,v] = uv;
        join(u*2,v*2+1);
        join(u*2+1,v*2);
        int x=find(u*2),y=find(u*2+1);
        if(x==y) {
            min_self(ans,1ll*w);
            break;
        }
        x = find(v*2),y=find(v*2+1);
        if(x==y) {
            min_self(ans,1ll*w);
            break;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}