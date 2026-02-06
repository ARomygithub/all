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
int n,m,t;
ll x[mxn],r[mxn];

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

void solve() {
    cin >>n >>m;
    LineContainer lc;
    rep(i,0,n) {
        cin >>x[i];
    }
    rep(i,0,n) {
        cin >>r[i];
    }
    rep(i,0,n) {
        ll ki = x[i]*2;
        ll mi = r[i]*r[i]-x[i]*x[i];
        lc.add(ki,mi);
    }
    vector<pll> v;
    rep(i,0,n) {
        v.push_back({x[i]-r[i],x[i]+r[i]});
    }
    sort(all(v));
    ll ri = -2e9;
    ll ans = 0;
    rep(i,0,sz(v)) {
        auto [l,rr] = v[i];
        if(ri>=rr) continue;
        max_self(ri, l-1);
        while(ri<rr) {
            ri++;
            ll qry = lc.query(ri);
            qry -= ri*ri;
            ll yi = floorl(sqrtl(qry));
            ans += yi*2+1;
        }
    }
    cout <<ans <<"\n";
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