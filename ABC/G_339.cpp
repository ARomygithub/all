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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

struct Vertex {
    Vertex *l, *r;
    ll sum;

    Vertex(ll val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(int a[], int tl, int tr) {
    if (tl == tr)
        return new Vertex(a[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
}

ll get_sum(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
         + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}

Vertex* update(Vertex* v, int tl, int tr, int pos, ll new_val) {
    if (tl == tr)
        return new Vertex(new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}

const int mxn=2e5;
int n,q;
int arr[mxn];

void solve() {
    cin >>n;
    vector<pii> v;
    rep(i,0,n) {
        int ai; cin >>ai;
        v.push_back({ai,i});
    } 
    sort(v.begin(),v.end());
    vector<Vertex*> rpst;
    rpst.push_back(build(arr, 0, n-1));
    rep(i,0,n) {
        rpst.push_back(update(rpst[i],0,n-1,v[i].se,v[i].fi));
        arr[v[i].se] = v[i].fi;
    } 
    cin >>q;
    ll last = 0;
    while(q--) {
        ll a,b,y; cin >>a >>b >>y;
        a ^=last;
        b ^=last;
        y ^=last;
        a--,b--;
        int ct = lower_bound(v.begin(),v.end(),make_pair((int)y,(int)1e9))-v.begin();
        last = get_sum(rpst[ct],0,n-1,a,b);
        cout <<last <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
/**
 * other technique:
 * - wavelet tree: https://miti-7.hatenablog.com/entry/2018/04/28/152259#%E3%82%A6%E3%82%A7%E3%83%BC%E3%83%96%E3%83%AC%E3%83%83%E3%83%88%E8%A1%8C%E5%88%97%E3%81%A7%E5%8F%AF%E8%83%BD%E3%81%AA%E6%93%8D%E4%BD%9C
 * - range tree: https://hitonanode.github.io/cplib-cpp/segmenttree/rangetree.hpp.html
 * 
