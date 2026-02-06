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
typedef pair<pii,ll> piil;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,q;
int cs[mxn], p[mxn];
ll dist[mxn];
vector<pii> adj[mxn];
piil abd[mxn];
bool vis[mxn];

void dfs(int u, int pp=-1) {
    vis[u] = 1;
    for(auto [v,d]: adj[u]) {
        if(v==pp) continue;
        dist[v] = dist[u]+d;
        dfs(v,u);
    }
}

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
}

void solve() {
    cin >>n >>q;
    set<int> s, s2;
    rep(i,0,q) {
        cin >>abd[i].fi.fi >>abd[i].fi.se >>abd[i].se;
        abd[i].fi.fi--;
        abd[i].fi.se--;
    }
    iota(p,p+n,0);
    fill(cs,cs+n,1);
    rep(i,0,q) {
        if(join(abd[i].fi.fi,abd[i].fi.se)) {
            s.insert(i);
        } else {
            s2.insert(i);
        }
    }
    for(int i : s) {
        int u = abd[i].fi.fi, v=abd[i].fi.se;
        adj[v].push_back({u,abd[i].se});
        adj[u].push_back({v,abd[i].se*-1});
        // cout <<"tes\n" <<flush;
    }
    rep(i,0,n) {
        if(!vis[i]) {
            int u = find(i);
            dfs(u,-1);
        }
    }
    for(int i2 : s2) {
        int u = abd[i2].fi.fi, v=abd[i2].fi.se;
        if(dist[u]-dist[v] == abd[i2].se) {
            s.insert(i2);
        }
    }
    for(auto it=s.begin();it!=s.end();it++) {
        if(it==s.begin()) {
            cout <<(*it)+1;
        } else {
            cout <<" " <<(*it)+1;
        }
    }
    cout <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}