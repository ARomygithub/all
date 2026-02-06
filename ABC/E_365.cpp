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

const int mxn=2e5+10, lg=30;
int n;
int a[mxn];

struct Node {
    ll sum; int num, val, pref[30], suf[30];
    Node(): num(0), sum(0), val(0) {
        memset(pref, 0, sizeof pref);
        memset(suf, 0, sizeof suf);
    }

    Node(int v): num(1), sum(v), val(v) {
        rep(j,0,lg) {
            suf[j] = pref[j] = (val>>j)&1;
        }
    }
};

typedef vector<ll> vl;
typedef Node T;
const T unit = Node();
struct Tree {
    T f(T a, T b) { 
        T res;
        res.num = a.num+b.num;
        res.val = a.val^b.val;
        res.sum = a.sum+b.sum;
        rep(j,0,lg) {
            res.sum += 1ll*(1<<j)*a.suf[j]*(b.num - b.pref[j]);
            res.sum += 1ll*(1<<j)*(a.num-a.suf[j])*b.pref[j];
        }
        rep(j,0,lg) {
            int curr = (a.val>>j)&1;
            res.pref[j] = a.pref[j] + (curr==0? b.pref[j]: b.num-b.pref[j]);
        }
        rep(j,0,lg) {
            int curr = (b.val>>j)&1;
            res.suf[j] = b.suf[j] + (curr==0? a.suf[j]: a.num-a.suf[j]);
        }
        return res;
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
    rep(i,0,n) {
        cin >>a[i];
    }
    Tree st(n);
    rep(i,0,n) {
        st.update(i,Node(a[i]));
    }
    auto res = st.query(0,n);
    ll ans = res.sum;
    rep(i,0,n) {
        ans -=a[i];
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}