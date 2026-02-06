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
int n,m,k;

struct UF {
    ll ans = 0;
    vi e, cta, ctb;
    UF(int n) : e(n, -1),cta(n,0),ctb(n,0) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b, int w) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        ll tmp = min(cta[a],ctb[b]);
        ans += tmp*w;
        cta[a] -= tmp;
        ctb[b] -= tmp;
        tmp = min(ctb[a], cta[b]);
        ans += tmp*w;
        ctb[a] -= tmp;
        cta[b] -= tmp;
        cta[a] += cta[b];
        ctb[a] += ctb[b];
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

using ipii = pair<int,pii>;

void solve() {
    cin >>n >>m >>k;
    UF uf(n);
    vector<ipii> e;
    rep(i,0,m) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        e.push_back({w,{u,v}});
    }
    sort(all(e));
    rep(i,0,k) {
        int ai; cin >>ai; ai--;
        uf.cta[ai]++;
    }
    rep(i,0,k) {
        int bi; cin >>bi; bi--;
        uf.ctb[bi]++;
    }
    for(auto [w,uv]: e) {
        auto [u,v] = uv;
        uf.join(u,v,w);
    }
    cout <<uf.ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}