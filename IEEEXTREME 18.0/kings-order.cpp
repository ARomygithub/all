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
int n,m;
int g[mxn], ind[mxn];
vi adj[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>g[i];
    }
    rep(i,0,m) {
        int u,v; cin >>u >>v;u--,v--;
        adj[u].push_back(v);
        ind[v]++;
    }
    vi ans;
    set<pii> s;
    rep(i,0,n) {
        if(ind[i]==0) {
            s.insert({g[i],i});
        }
    }
    while(sz(s)) {
        auto [gid, id] = *s.begin();
        ans.push_back(id);
        s.erase(s.begin());
        for(auto v: adj[id]) {
            ind[v]--;
            if(ind[v]==0) {
                s.insert({g[v],v});
            }
        }
    }
    if(sz(ans)==n) {
        rep(i,0,n) {
            cout <<ans[i]+1 <<" \n"[i==n-1];
        }
    } else {
        cout <<"-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}