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

const int mxn=3e5;
int n;
vi adj[mxn];
int ans = 0;

void dfs(int u, int p=-1) {
    multiset<int> s;
    for(int v: adj[u]) {
        s.insert(sz(adj[v])-1);
    }
    int x = sz(adj[u]);
    auto it = s.begin();
    while(it!=s.end()) {
        int y = *it;
        if(y>0) {
            max_self(ans, y*x + x + 1);
        }
        x--;
        it++;
    }
    for(int v: adj[u]) {
        if(v==p) continue;
        dfs(v,u);
    }
}

void solve() {
    cin >>n;
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    cout <<n-ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}