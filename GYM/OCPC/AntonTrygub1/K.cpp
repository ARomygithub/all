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

const int mxn=2e5;
int n,m,t;

void solve() {
    cin >>n >>m;
    vector adj(n, vi());
    vector adj2(n, vi());
    rep(i,0,m) {
        int x,y; cin >>x >>y; x--,y--;
        adj[x].push_back(y);
        adj2[y].push_back(x);
    }
    auto cek = [&](vector<vi>& adji) -> bool {
        vector<bool> vis(n,0);
        function<void(int)> dfs;
        dfs = [&](int u) -> void {
            vis[u] = 1;
            for(int v: adji[u]) {
                if(!vis[v]) {
                    dfs(v);
                }
            }
        };
        dfs(0);
        rep(i,0,n) {
            if(!vis[i]) return false;
        }
        return true;
    };
    bool ok = cek(adj);
    if(!ok) {
        cout <<"NO\n";
        return;
    }
    ok = cek(adj2);
    if(!ok) {
        cout <<"NO\n";
    } else {
        cout <<"YES\n";
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