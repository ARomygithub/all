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

const int mxn=1e5;
int n,m,t;
int c[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>c[i];
    }
    vector adj(mxn+1,set<int>());
    int ans = -1, ct = -1;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        if(c[u]!=c[v]) {
            adj[c[u]].insert(c[v]);
            adj[c[v]].insert(c[u]);
        }
    }
    int mn = mxn;
    rep(i,0,n) {
        min_self(mn, c[i]);
    }
    ans = mn, ct = 0;
    rep(i,1,mxn+1) {
        int szi = sz(adj[i]);
        if(szi>ct) {
            ct = szi;
            ans = i;
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