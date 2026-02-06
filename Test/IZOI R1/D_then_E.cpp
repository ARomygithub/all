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
int n,t;
ll w;
int p[mxn];

void solve() {
    cin >>n >>w;
    vector adj(n, vi());
    rep(i,1,n) {
        cin >>p[i]; p[i]--;
        adj[p[i]].push_back(i);
    }
    vector<ll> ans(n-1,w*n);
    vi on(n,0);
    vector path(n, vi());
    vi tout(n,0);
    function<void(int,int)> dfs;
    dfs = [&](int u, int par) ->void {
        tout[u] = u;
        for(int v: adj[u]) {
            if(v==par) continue;
            dfs(v,u);
            path[v].push_back(v-1);
            on[v-1]++;
            path[v].push_back(tout[v]);
            on[tout[v]]++;
            max_self(tout[u],tout[v]);
        }
    };
    dfs(0,-1);
    ll temp = 0;
    int tmp2 = n;
    rep(i,1,n) {
        int x; ll tx; cin >>x >>tx; x--;
        for(auto pathi: path[x]) {
            on[pathi]--;
            if(on[pathi]==0) {
                tmp2--;
            }
        }
        temp += tx*(n-2);
        ans[i-1] -= temp;
    }
    rep(i,0,n-1) {
        cout <<ans[i] <<" \n"[i==n-2];
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