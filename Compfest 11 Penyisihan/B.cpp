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

const int mxn=1e5;
int n,q;
int a[mxn];

typedef vector<ll> vl;
typedef vector<pair<vector<vl>,int>> T;
const T unit = vector(30, make_pair(vector<vl>(3, vl{0,0}),-1));
struct Tree {
    T f(T a, T b) { 
        T res = unit;
        rep(bit,0,30) {
            rep(i,0,3) {
                rep(j,0,2) {
                    if(i==0) { //pref
                        res[bit].fi[i][j] += a[bit].fi[i][j];
                    } else if(i==2) { // suf
                        res[bit].fi[i][j] += b[bit].fi[i][j];
                    } else {
                        res[bit].fi[i][j] += a[bit].fi[i][j]+b[bit].fi[i][j];
                    }
                }
            }
            if(a[bit].se!=-1 || b[bit].se!=-1) {
                int tmp = 0;
                if(a[bit].se!=-1) {
                    tmp ^=a[bit].se;
                }
                if(b[bit].se!=-1) {
                    tmp ^=b[bit].se;
                }
                res[bit].se = tmp;
                if(a[bit].se!=-1) {
                    rep(i,0,2) {
                        res[bit].fi[0][i] += b[bit].fi[0][i^a[bit].se];
                    }
                }
                if(b[bit].se!=-1) {
                    rep(i,0,2) {
                        res[bit].fi[2][i] += a[bit].fi[2][i^b[bit].se];
                    }
                }
            }
            rep(i,0,2) {
                rep(j,0,2) {
                    res[bit].fi[1][i^j] += a[bit].fi[2][i]*b[bit].fi[0][j];
                }
            }
        }
        return res;
    } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, int vali) {
        T val = unit;
        rep(bit,0,30) {
            if((vali>>bit)&1) {
                val[bit] = make_pair(vector<vl>(3, vl{0,1}) ,1);
            } else {
                val[bit] = make_pair(vector<vl>(3, vl{1,0}), 0);
            }
        }
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
    rep(i,0,n) {
        cin >>a[i];
    }
    Tree st(n);
    rep(i,0,n) {
        st.update(i, a[i]);
    }
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int x,v; cin >>x >>v; x--;
            st.update(x, v);
        } else {
            int x,y; cin >>x >>y; x--,y--;
            auto res = st.query(x,y+1);
            ll ans = 0;
            rep(bit,0,30) {
                ans += res[bit].fi[1][1]*(1<<bit);
            }
            cout <<ans <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}