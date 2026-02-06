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

const int mxn=2e5;
int n,q;

struct Block {
    int fL, fU;
    int gL, gU;
    ll C;
    pair<int,ll> operator()(int y) const {
        return {clamp(y, fL, fU), C + max(y,gL)-min(y,gU)};
    }
};

struct Tree {
    typedef Block T;
    static constexpr T unit = Block{0, 1000000001, 0, 1000000001, 0};
    T f(T a, T b) { 
        int new_fL{clamp(a.fL, b.fL, b.fU)}, new_fU{clamp(a.fU, b.fL, b.fU)};
        int new_gL{clamp(b.gL, a.gL, a.gU)}, new_gU{clamp(b.gU, a.gL, a.gU)};
        ll new_C{a.C + b(a(new_gU).fi).se};
        return Block{new_fL, new_fU, new_gL, new_gU, new_C};
     } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    cin >>n;
    Tree st(n);
    rep(i,0,n) {
        int li,ui; cin >>li >>ui;
        st.update(i, Block{li,ui,li,ui,1});
    }
    
    cin >>q;
    while(q--) {
        int sx,sy,tx,ty;
        cin >>sx >>sy >>tx >>ty;
        if(sx>tx) {
            swap(sx,tx);
            swap(sy,ty);
        }
        auto [out, cost] = st.query(sx, tx)(sy);
        cout <<max(out,ty)-min(out,ty) + cost <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}