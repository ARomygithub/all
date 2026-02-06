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

const int mxn=2e3;
int n,t;
vector<int> adj[mxn];

void solve() {
    cin >>n;
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int diam = 0;
    vector<int> d(n,0);
    function<pii(int,int)> dfs1;
    pii leaf;
    dfs1 = [&](int u, int p=-1) -> pii {
        pii ret = {d[u],u};
        pii ch = {-1,-1};
        pii chi;
        for(int v: adj[u]) {
            if(v==p) continue;
            d[v] = d[u]+1;
            pii retc = dfs1(v,u);
            if(ch.fi==-1) {
                ch.fi = retc.fi;
                chi.fi = retc.se;
            } else if(retc.fi>ch.fi) {
                ch.se = ch.fi;
                chi.se = chi.fi;
                ch.fi = retc.fi;
                chi.fi = retc.se;
            } else if(retc.fi>ch.se) {
                ch.se = retc.fi;
                chi.se = retc.se;
            }
            max_self(ret, retc);
        }
        if(ch.se!=-1) {
            if(ch.fi+ch.se-d[u]*2 > diam) {
                diam = ch.fi+ch.se-d[u]*2;
                leaf = chi;
            }
        }
        if(d[u]>diam) {
            diam = d[u];
            leaf = {0,u};
        }
        return ret;
    };
    dfs1(0,-1);
    // cout <<diam <<endl;
    // cout <<leaf.fi <<" " <<leaf.se <<"\n";
    pii center = {-1,-1};
    d[leaf.fi] = 0;
    function<bool(int,int)> dfs2;
    dfs2 = [&](int u, int p) -> bool {
        bool ret = u==leaf.se;
        int ch = -1;
        for(int v: adj[u]) {
            if(v==p) continue;
            d[v] = d[u]+1;
            int retc = dfs2(v,u);
            ret |= retc;
            if(retc) {
                ch = v;
            }
        }
        if(d[u]==(diam/2) && ret) {
            center = {u,ch};
        }
        return ret;
    };
    dfs2(leaf.fi, -1);
    vector<pii> ans;
    if(diam%2) {
        int hd = diam/2;
        for(int i=1;i<=hd+1;i+=2) {
            ans.push_back({center.fi,i});
            ans.push_back({center.se,i});
        }
    } else {
        // cout <<"tes" <<endl;
        rep(i,0,(diam/2)+1) {
            ans.push_back({center.fi,i});
        }
    }
    cout <<sz(ans) <<"\n";
    for(auto [v, dist]: ans) {
        cout <<v+1 <<" " <<dist <<"\n";
    }
    rep(i,0,n) {
        adj[i].clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}