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
int n,m,t;

void solve() {
    cin >>n >>m;
    vector adj(n, vector<int>());
    vector<pii> ord;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        ord.push_back({v,u});
    }
    sort(ord.begin(),ord.end());
    vector<bool> vis(n,0);
    vector<int> cl(n,0);
    rep(i,0,m) {
        auto [v,u] = ord[i];
        if(vis[v]) continue;
        if(cl[u]==0) {
            vis[v] = 1;
            cl[v] = 1;
            for(int w: adj[v]) {
                if(!vis[w]) {
                    vis[w] = 1;
                    cl[w] = 2;
                }
            }
        }
    }
    vector<int> ans;
    rep(i,0,n) {
        if(cl[i]==2) {
            ans.push_back(i);
        }
    }
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i]+1 <<" \n"[i==sz(ans)-1];
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