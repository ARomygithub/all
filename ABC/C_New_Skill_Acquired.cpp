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
vi adj[mxn];

void solve() {
    cin >>n;
    vector<bool> vis(n,0);
    queue<int> q;
    rep(i,0,n) {
        int x,y; cin >>x >>y; x--,y--;
        if(x==-1) {
            vis[i] = 1;
            q.push(i);
        } else {
            adj[x].push_back(i);
            adj[y].push_back(i);
        }
    }
    while(sz(q)) {
        auto u = q.front(); q.pop();
        for(int v: adj[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    int ct = 0;
    rep(i,0,n) {
        ct += vis[i];
    }
    cout <<ct <<"\n";
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