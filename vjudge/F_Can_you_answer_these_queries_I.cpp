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

const int mxn=5e4;
int n;

struct Nd {
    ll mn,mx,ans;
    Nd(ll x): mn(x),mx(x),ans(-1e18) {}
    Nd(): mn(0),mx(0),ans(-1e18) {}
};

Nd unit(1e18);

struct Tree {
    typedef Nd T;
    T f(T a, T b) { 
        if(a.mn==unit.mn) return b;
        if(b.mn==unit.mn) return a;
        T ret;
        ret.mn = min(a.mn,b.mn);
        ret.mx = max(a.mx,b.mx);
        ret.ans = max(a.ans,b.ans);
        max_self(ret.ans, b.mx - a.mn);
        return ret;
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
    vector<ll> a(n+1);
    rep(i,1,n+1) {
        cin >>a[i];
    }
    rep(i,2,n+1) {
        a[i] += a[i-1];
    }
    Tree st(n+1);
    rep(i,0,n+1) {
        st.update(i, Nd(a[i]));
    }
    int q; cin >>q;
    while(q--) {
        int l,r; cin >>l >>r;
        cout <<st.query(l-1,r+1).ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}