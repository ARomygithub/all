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
typedef pair<int,pii> ipii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int m,n;
int a[mxn],b[mxn];

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

void solve() {
    cin >>m >>n;
    rep(i,0,m) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    vector<ipii> v;
    ll ans = 0;
    rep(i,0,m) {
        int si; cin >>si;
        rep(j,0,si) {
            int sij; cin >>sij; sij--;
            ans += a[i]+b[sij];
            v.push_back({a[i]+b[sij], {sij, n+i}});
        }
    }
    sort(v.begin(), v.end());
    UF uf(n+m);
    per(i,sz(v)-1,-1) {
        if(uf.join(v[i].se.fi,v[i].se.se)) {
            ans -= v[i].fi;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}