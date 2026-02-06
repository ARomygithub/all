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

const int mxn=5e5;
int n,m,k;
int c[mxn];

struct RollbackUF {
    vi e; vector<pii> st;
    RollbackUF(int n) : e(n, -1) {}
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    int time() { return sz(st); }
    void rollback(int t) {
        for (int i = time(); i --> t;)
            e[st[i].first] = st[i].second;
        st.resize(t);
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        st.push_back({a, e[a]});
        st.push_back({b, e[b]});
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

void solve() {
    cin >>n >>m >>k;
    RollbackUF ruf(n*2);
    vector nk(k, vi());
    rep(i,0,n) {
        cin >>c[i]; c[i]--;
        nk[c[i]].push_back(i);
    }
    vector<pii> ed;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        if(c[u]==c[v]) {
            ruf.join(u*2,v*2+1);
            ruf.join(u*2+1,v*2);
        } else {
            if(c[u]>c[v]) swap(u,v);
            ed.push_back({u,v});
        }
    }
    set<int> vld;
    rep(i,0,k) {
        vld.insert(i);
    }
    rep(i,0,n) {
        if(ruf.find(i*2)==ruf.find(i*2+1)) {
            vld.erase(c[i]);
        }
    }
    ll ans = 1ll*sz(vld)*(sz(vld)-1)/2;
    sort(all(ed), [&](pii uv, pii xy) -> bool {
        auto [u,v] = uv;
        auto [x,y] = xy;
        return pii{c[u],c[v]} < pii{c[x],c[y]};
    });
    for(int i=0;i<sz(ed);) {
        int j = i;
        while(j<sz(ed) && c[ed[j].fi]==c[ed[i].fi] && c[ed[j].se]==c[ed[i].se]) {
            j++;
        }
        int cu = c[ed[i].fi], cv = c[ed[i].se];
        if(vld.count(cu) && vld.count(cv)) {
            int tm = ruf.time();
            bool ok = 1;
            rep(l,i,j) {
                auto [u,v] = ed[l];
                ruf.join(u*2,v*2+1);
                ruf.join(u*2+1,v*2);
                if(ruf.find(u*2)==ruf.find(u*2+1)) {
                    ok = 0;
                    break;
                }
            }
            if(!ok) {
                ans--;
            }
            ruf.rollback(tm);
        }
        i = j;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}