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


const int mxn=5e5;
int n,q;
int arr[mxn];

struct TreeMx {
    typedef pii T;
    static constexpr T unit = {-1,-1};
    T f(T a, T b) { 
        T vala = {a.fi==-1?INT_MIN:arr[a.fi], a.se==-1?INT_MIN:arr[a.se]};
        T valb = {b.fi==-1?INT_MIN:arr[b.fi], b.se==-1?INT_MIN:arr[b.se]};
        T ret;
        if(vala.fi>=valb.fi) {
            ret.fi = a.fi;
            if(vala.se>=valb.fi) {
                ret.se = a.se;
            } else {
                ret.se = b.fi;
            }
        } else {
            ret.fi = b.fi;
            if(valb.se>=vala.fi) {
                ret.se = b.se;
            } else {
                ret.se = a.fi;
            }
        }
        return ret;
    } // (any associative fn)
    vector<T> s; int n;
    TreeMx(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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

struct TreeMn {
    typedef pii T;
    static constexpr T unit = {-1,-1};
    T f(T a, T b) { 
        T vala = {a.fi==-1?INT_MAX:arr[a.fi], a.se==-1?INT_MAX:arr[a.se]};
        T valb = {b.fi==-1?INT_MAX:arr[b.fi], b.se==-1?INT_MAX:arr[b.se]};
        T ret;
        if(vala.fi<=valb.fi) {
            ret.fi = a.fi;
            if(vala.se<=valb.fi) {
                ret.se = a.se;
            } else {
                ret.se = b.fi;
            }
        } else {
            ret.fi = b.fi;
            if(valb.se<=vala.fi) {
                ret.se = b.se;
            } else {
                ret.se = a.fi;
            }
        }
        return ret;            
    } // (any associative fn)
    vector<T> s; int n;
    TreeMn(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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
    cin >>n >>q;
    TreeMn tmn(n);
    TreeMx tmx(n);
    rep(i,0,n) {
        cin >>arr[i];
        tmn.update(i, pii({i,-1}));
        tmx.update(i, pii({i,-1}));
    }
    while(q--) {
        int l,r; cin >>l >>r; l--,r--;
        ll ans = 1ll*arr[l]*arr[r];
        pii retmn = tmn.query(l+1,r);
        pii retmx = tmx.query(l+1,r);
        if(ans>=0) {
            ll temp = max(1ll*arr[retmn.fi]*arr[retmn.se], 1ll*arr[retmx.fi]*arr[retmx.se]);
            ans *= temp;
        } else {
            ll temp = min(1ll*arr[retmn.fi]*arr[retmn.se], 1ll*arr[retmx.fi]*arr[retmx.se]);
            min_self(temp, 1ll*arr[retmx.fi]*arr[retmn.fi]);
            ans *= temp;
        }
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}