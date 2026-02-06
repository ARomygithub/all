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
int n,m,q,t;
int h[mxn];

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

using ipii = pair<int,pii>;
using pipi = pair<pii,pii>;
void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>h[i];
    }
    vector<ipii> ed;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        ed.push_back({max(h[u],h[v]), {u,v}});
    }
    sort(all(ed));
    cin >>q;
    vector<pipi> qry(q);
    rep(i,0,q) {
        int a,b,e; cin >>a >>b >>e; a--,b--;
        qry[i] = {{h[a]+e,i}, {a,b}};
    }
    sort(all(qry));
    UF uf(n);
    vector<bool> ans(q,0);
    int id = 0;
    rep(i,0,q) {
        auto [btsi, ab] = qry[i];
        auto [bts, iq] = btsi;
        auto [a,b] = ab;
        while(id<sz(ed) && ed[id].fi<=bts) {
            uf.join(ed[id].se.fi, ed[id].se.se);
            id++;
        }
        if(uf.sameSet(a,b)) {
            ans[iq] = 1;
        }
    }
    rep(i,0,q) {
        if(ans[i]) {
            cout <<"YES\n";
        } else {
            cout <<"NO\n";
        }
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