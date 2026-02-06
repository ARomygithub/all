#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef vector<int> vi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n;
vector<int> adj[mxn], vd;
int d = 0, de[mxn], ans[mxn];
pii pd;
int ct = 1, idx;

pii dfs1(int u, int p=-1) {
    pii c1 = {de[u],u};
    pii c2 = {de[u], u};
    for(int v: adj[u]) {
        if(v==p) continue;
        de[v] = de[u]+1;
        pii temp = dfs1(v,u);
        if(temp>c1) {
            c2 = c1;
            c1 = temp;
        } else if(temp>c2) {
            c2 = temp;
        }
    }
    if(c1.fi>d) {
        d = c1.fi;
        pd = {0, c1.se};
    }
    if(c1.fi-de[u]+c2.fi-de[u] > d) {
        d = c1.fi-de[u]+c2.fi-de[u];
        pd = {c1.se, c2.se};
    } 
    return c1;
}

bool dfs2(int u, int p=-1) {
    bool ok = u==pd.se;
    for(int v: adj[u]) {
        if(v==p) continue;
        ok = ok | dfs2(v,u);
    }
    if(ok) {
        vd.push_back(u);
    }
    return ok;
}

void dfs3(int u, int p=-1) {
    ans[u] = ct;
    bool ada = 0;
    for(int v: adj[u]) {
        if(v==p) continue;
        if(v!=vd[idx]) {
            ct++;
            dfs3(v,u);
        } else {
            ada = 1;
        }
    }
    if(ada) {
        ct++;
        idx--;
        dfs3(vd[idx+1], u);
    }
    ct++;
}

void solve() {
    cin >>n;
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(0,-1);
    dfs2(pd.fi,-1);
    idx = sz(vd)-2;
    dfs3(pd.fi, -1);
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}