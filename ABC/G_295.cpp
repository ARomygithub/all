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
int n,q;
set<int> adj[mxn],adj2[mxn];
int ch[mxn],d[mxn],ansd[mxn];
int p[mxn],cs[mxn];
map<int,int> mp;

int find(int x) {
    return x==p[x]?x:(p[x]=find(p[x]));
}

int join(int x, int y) {
    if((x=find(x))==(y=find(y))) {
        return x;
    }
    vector<int> atas, bwh;

    if(cs[x]>cs[y] && y!=0) swap(x,y);
    p[x] = y;
    cs[y] += cs[x];
    if(d[ansd[y]]>d[ansd[x]]) {
        ansd[y] = ansd[x];
    }
    adj[y].erase(x);
    for(int v: adj[x]) {
        adj2[v].clear();
        if(v!=y) {
            adj2[v].insert(y);
            adj[y].insert(v);
        }
    }
    if(sz(adj2[x])) {
        if((*adj2[x].begin())!=y) {
            int v = *adj2[x].begin();
            adj[v].erase(x);
            adj[v].insert(y);
            adj2[y].clear();
            adj2[y].insert(v);
        }
        adj2[x].clear();
    }
    return y;
}

void dfs(int u) {
    if(u==0) {
        int i = 0;
        for(int v: adj[u]) {
            ch[v] = i;
            d[v] = d[u]+1;
            ansd[v] = v;
            dfs(v);
            i++;
        }
        mp[0] = 0;
    } else {
        int ans = u;
        for(int v: adj[u]) {
            ch[v] = ch[u];
            d[v] =d[u]+1;
            ansd[v] = v;
            dfs(v);
            min_self(ans, mp[v]);
        }
        mp[u] = ans;
        // cout <<u <<" " <<ans <<endl;
        // cout <<mp[{ch[3],ansd[3]}] <<endl;
    }
}

void solve() {
    cin >>n;
    rep(i,1,n) {
        int pi; cin >>pi; pi--;
        adj[pi].insert(i);
        adj2[i].insert(pi);
    }
    dfs(0);
    iota(p,p+n,0);
    fill(cs,cs+n,1);
    cin >>q;
    while(q--) {
        int qt; cin >>qt; 
        if(qt==1) {
            int u,v; cin >>u >>v; u--,v--;
            u = find(u), v=find(v);
            while(u!=v) {
                int u2 = *adj2[u].begin();
                u = join(u,u2);
                if(u2==v) break;
            }
        } else {
            int x; cin >>x; x--;
            x = find(x);
            cout <<mp[ansd[x]]+1 <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}