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

const int mxn=500;
int n,m,q;
int a[mxn][mxn];

struct Tree {
    typedef pii T;
    static constexpr T unit = {INT_MIN,INT_MAX};
    T f(T a, T b) { return {max(a.fi,b.fi),min(a.se,b.se)}; } // (any associative fn)
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
    cin >>n >>m;
    Tree str(n*m),stc(n*m);
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>a[i][j];
            str.update(a[i][j], {i,i});
            stc.update(a[i][j], {j,j});
        }
    }
    cin >>q;
    int add = 0;
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int r1,c1,r2,c2; cin >>r1 >>c1 >>r2 >>c2; r1--,c1--,r2--,c2--;
            int val1 = a[r1][c1], val2 = a[r2][c2];
            str.update(val1, {r2,r2});
            str.update(val2, {r1,r1});
            stc.update(val1, {c2,c2});
            stc.update(val2, {c1,c1});
            swap(a[r1][c1],a[r2][c2]);
        } else if(qt==2) {
            int w; cin >>w;
            add = (add+w)%(n*m);
        } else {
            int r1,c1,r2,c2; cin >>r1 >>c1 >>r2 >>c2; r1--,r2--,c1--,c2--;
            int start = (n*m-add)%(n*m);
            int pos = start+n*m;
            int l = start, r = start+n*m-1;
            while(l<=r) {
                int mid = (l+r)/2;
                int val = (mid)%(n*m);
                bool ok = 0;
                if(start<=val) {
                    pii qry1 = str.query(start, val+1);
                    if(qry1.fi>r2 || qry1.se<r1) {
                        ok = 1;
                    }
                    pii qry2 = stc.query(start, val+1);
                    if(qry2.fi>c2 || qry2.se<c1) {
                        ok = 1;
                    }
                } else {
                    pii qry1 = str.query(start, n*m);
                    if(qry1.fi>r2 || qry1.se<r1) {
                        ok = 1;
                    }
                    qry1 = str.query(0, val+1);
                    if(qry1.fi>r2 || qry1.se<r1) {
                        ok = 1;
                    }
                    pii qry2 = stc.query(start, n*m);
                    if(qry2.fi>c2 || qry2.se<c1) {
                        ok = 1;
                    }
                    qry2 = stc.query(0, val+1);
                    if(qry2.fi>c2 || qry2.se<c1) {
                        ok = 1;
                    }
                }
                if(ok) {
                    pos = mid;
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            if(pos-start==n*m) {
                cout <<"-1\n";
            } else {
                cout <<pos-start <<"\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}