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

// typedef pair<int,string> pis;
typedef pair<int,ll> pil;

const int mxn=1e5,mxl=6e5;
const ll mod=1e9+7;
int n,m;
set<pii> adj[mxn];
typedef pair<pll,ll> plll;

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].insert({i+1, v});
        adj[v].insert({i+1, u});
    }
    vector<pll> ans(n, {1e9,0});
    ans[0] = {0,0};
    vector pq(7, queue<pil>());
    pq[0].push({0,0});
    rep(i,0,mxl+1) {
        while(sz(pq[i%7])) {
            auto [u,val] = pq[i%7].front(); pq[i%7].pop();
            if(ans[u].fi > i) {
                ans[u] = {i, val};
            }
            for(auto [mi, v]: adj[u]) {
                int len = sz(to_string(mi));
                ll nval = val;
                rep(j,0,len) {
                    nval = nval*10ll%mod;
                }
                nval = (nval + mi)%mod;
                if(ans[v].fi > i+len) {
                    pq[(i+len)%7].push({v,nval});
                }
            }
        }
    }
    rep(i,1,n) {
        cout <<ans[i].se <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}