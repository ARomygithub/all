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

const int mxn=2e3;
int n,m;
vi adj[mxn];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using b = bitset<2000>; 

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi deg(n);
    rep(i,0,n) {
        deg[i] = sz(adj[i]);
    }
    set<pii> s;
    rep(i,0,n) {
        s.insert({deg[i],i});
    }
    vi v1;
    int p = -1;
    while(sz(s)) {
        while(sz(s) && (*s.begin()).fi <= p) {
            auto u = (*s.begin()).se;
            s.erase(s.begin());
            for(auto v: adj[u]) {
                if(s.count({deg[v],v})) {
                    s.erase({deg[v],v});
                    deg[v]--;
                    s.insert({deg[v],v});
                }
            }
        }
        if(sz(s)) {
            p = (*s.begin()).fi;
            v1.clear();
            for(auto [d,si]: s) {
                v1.push_back(si);
            }
        }
    }
    int qm = (n+1+p)/(p+1) - 1;
    max_self(qm, 1);
    vi id(n);
    iota(all(id),0);
    vector<b> vb(n);
    rep(i,0,n) {
        vb[i][i] = 1;
        for(int j: adj[i]) {
            vb[i][j] = 1;
        }
    }
    int iter = 0;
    while(true) {
        iter++;
        shuffle(all(id), rng);
        // sort(all(id), [&](int i, int j)-> bool {
        //     return sz(adj[i])<sz(adj[j]);
        // });
        vi v2;
        b bit;
        rep(i,0,sz(id)) {
            if(sz(id)-i + sz(v2) < qm) break;
            auto u = id[i];
            if(bit[u]) continue;
            v2.push_back(u);
            bit |= vb[u];
            if((int)(n-bit.count()) + sz(v2) < qm) break;
        }
        if((p+1)*(sz(v2)+1) > n) {
            cout <<p <<" " <<sz(v2) <<"\n";
            cout <<sz(v1) <<" ";
            rep(i,0,sz(v1)) {
                cout <<v1[i]+1 <<" \n"[i==sz(v1)-1];
            }
            cout <<sz(v2) <<" ";
            rep(i,0,sz(v2)) {
                cout <<v2[i]+1 <<" \n"[i==sz(v2)-1];
            }
            return;
        }
        assert(iter!=10000);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}