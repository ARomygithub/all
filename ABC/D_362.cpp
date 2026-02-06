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
int n,m;
int a[mxn];
vector<pii> adj[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,m) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    vector<ll> ans(n, 1e18);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    ans[0] = a[0];
    pq.push({a[0], 0});
    while(sz(pq)) {
        auto [du, u] = pq.top(); pq.pop();
        if(ans[u]<du) continue;
        for(auto [w,v]: adj[u]) {
            if(ans[v] > du+w+a[v]) {
                ans[v] = du+w+a[v];
                pq.push({ans[v],v});
            }
        }
    }
    rep(i,1,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}