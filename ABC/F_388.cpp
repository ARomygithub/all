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

const int mxn=2e4;
ll n;
int m,a,b;
ll l[mxn],r[mxn];

template<class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M& m) const {
        M a;
        rep(i,0,N) rep(j,0,N)
            rep(k,0,N) a.d[i][j] = a.d[i][j] || (d[i][k]&&m.d[k][j]);
        return a;
    }
    vector<T> operator*(const vector<T>& vec) const {
        vector<T> ret(N);
        rep(i,0,N) rep(j,0,N) ret[i] = ret[i] || (d[i][j] && vec[j]);
        return ret;
    }
};

void solve() {
    cin >>n >>m >>a >>b;
    rep(i,0,m) {
        cin >>l[i] >>r[i];
    }
    vector<Matrix<bool,20>> vmat(40);
    rep(i,0,20) {
        if(i>0) {
            vmat[0].d[i][i-1] = 1;
        } else {
            rep(j,0,20) {
                if(a<=j+1 && j+1<=b) {
                    vmat[0].d[i][j] = 1;
                }
            }
        }
    }
    rep(i,1,40) {
        vmat[i] = vmat[i-1]*vmat[i-1];
    }
    auto getmat = [&](ll x) -> Matrix<bool,20> {
        Matrix<bool,20> ret;
        rep(i,0,20) {
            ret.d[i][i] = 1;
        }
        rep(i,0,40) {
            if((x>>i)&1) {
                ret = ret*vmat[i];
            }
        }
        return ret;
    };
    ll cur = 1;
    vector<bool> v(20,0);
    v[0] = 1;
    rep(i,0,m) {
        if(cur<l[i]-1) {
            v = getmat(l[i]-1-cur)*v;
        }
        vector<bool> vn(20,0);
        rep(j,0,20) {
            ll pos = r[i]-j;
            if(pos<l[i]) {
                vn[j] = v[l[i]-1 - pos];
            }
        }
        v.swap(vn);
        cur = r[i];
    }
    if(cur<n) {
        v =  getmat(n-cur)*v;
    }
    if(v[0]) {
        cout <<"Yes\n";
    } else {
        cout <<"No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}