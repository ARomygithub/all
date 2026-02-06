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

const int mxn=1e5;
int n,m,q;
string s,t;

struct Tree {
    typedef int T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a+b; } // (any associative fn)
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
    cin >>n >>m >>q;
    cin >>s >>t;
    Tree sg(n+m);
    string st = s+t, ts = t+s;
    rep(i,0,n+m) {
        sg.update(i, (st[i]==ts[i]));
    }
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int id; char c; cin >>id >>c;
            st[id-1] = c;
            ts[m+id-1] = c;
            sg.update(id-1, (st[id-1]==ts[id-1]));
            sg.update(m+id-1, (st[m+id-1]==ts[m+id-1]));
        } else if(qt==2) {
            int id; char c; cin >>id >>c;
            ts[id-1] = c;
            st[n+id-1] = c;
            sg.update(id-1, (st[id-1]==ts[id-1]));
            sg.update(n+id-1, (st[n+id-1]==ts[n+id-1]));
        } else {
            ll x; cin >>x;
            ll sm = sg.query(0,n+m);
            ll qry = sm*(x/(n+m));
            int r = x%(n+m);
            if(r) {
                qry += sg.query(0,r);
            }
            cout <<qry <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}