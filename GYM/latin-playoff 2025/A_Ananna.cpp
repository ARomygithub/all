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

const int mxn=5e3;
int n,m,t;
bool pal[mxn][mxn];
using pic = pair<int,char>;
vector<pic> adj[mxn], adj2[mxn];

void solve() {
    cin >>n >>m;
    queue<pii> q;
    rep(i,0,n) {
        q.push({i,i});
        pal[i][i] = 1;
    }
    rep(i,0,m) {
        int u,v; char c; cin >>u >>v >>c; u--,v--;
        adj[u].push_back({v,c});
        adj2[v].push_back({u,c});
        if(!pal[u][v]) {
            q.push({u,v});
            pal[u][v] = 1;
            // pal[v][u] = 1;
        }
    }
    while(sz(q)) {
        auto [u,v] = q.front(); q.pop();
        for(auto [u2,cu]: adj2[u]) {
            for(auto [v2,cv]: adj[v]) {
                if(cu==cv) {
                    if(!pal[u2][v2]) {
                        q.push({u2,v2});
                        pal[u2][v2] = 1;
                    }
                }
            }
        }
    }
    int ans = 0;
    rep(i,0,n) {
        rep(j,0,n) {
            if(i==j) continue;
            ans += pal[i][j];
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}