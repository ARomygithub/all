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
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e3;
int n;
vi adj[mxn+1];
bool vis[mxn+1];
int val[mxn+1];
bool ok = 1;

void dfs(int u) {
    if(!ok) return;
    vis[u] = 1;
    for(int v: adj[u]) {
        if(vis[v]) {
            if(val[u]==val[v]) {
                ok = 0;
                return;
            }
        } else {
            val[v] = 1-val[u];
            dfs(v);
        }
    }
}

void solve() {
    cin >>n;
    vi tin(n+1,-1),tout(n+1,-1);
    rep(i,0,n*2) {
        int cur; cin >>cur;
        if(cur<0) {
            cur *= -1;
            tout[cur] = i;
        } else {
            tin[cur] = i;
        }
    }
    rep(i,1,n+1) {
        rep(j,i+1,n+1) {
            pii u = {tin[i],tout[i]};
            pii v = {tin[j],tout[j]};
            if(u>v) swap(u,v);
            if(v.fi<u.se && v.se > u.se) {
                // cout <<i <<" " <<j <<endl;
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    rep(i,1,n+1) {
        if(!vis[i]) {
            val[i] = 0;
            dfs(i);
        }
    }
    if(!ok) {
        cout <<"*\n";
        return;
    }
    rep(i,1,n+1) {
        if(val[i]==0) {
            cout <<"G";
        } else {
            cout <<"S";
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