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
ll n;

const ll mod = 1e9+7; // faster if const
template<class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M& m) const {
        M a;
        rep(i,0,N) rep(j,0,N)
            rep(k,0,N) a.d[i][j] = (a.d[i][j] + d[i][k]*m.d[k][j]%mod)%mod;
        return a;
    }
    vector<T> operator*(const vector<T>& vec) const {
        vector<T> ret(N);
        rep(i,0,N) rep(j,0,N) ret[i] = (ret[i] + d[i][j] * vec[j]%mod)%mod;
        return ret;
    }
    M operator^(ll p) const {
        assert(p >= 0);
        M a, b(*this);
        rep(i,0,N) a.d[i][i] = 1;
        while (p) {
            if (p&1) a = a*b;
            b = b*b;
            p >>= 1;
        }
        return a;
    }
};

void solve() {
    // vector<ll> fibo(10);
    // fibo[0] = 0, fibo[1] = 1;
    // rep(i,2,10) {
    //     fibo[i] = fibo[i-1]+fibo[i-2];
    // }
    // vector<ll> seq(10);
    // ll pr = 0;
    // rep(i,0,10) {
    //     pr = (pr + fibo[i]*fibo[i])%mod;
    //     seq[i] = pr;
    //     cout <<seq[i] <<endl;
    // }
    // auto linrec = berlekampMassey(seq);
    // rep(i,0,sz(linrec)) {
    //     cout <<linrec[i] <<",";
    // }
    cin >>n;
    ll n1 = mod-1;
    Matrix<ll,3> mat;
    mat.d = {{ {{2,2,n1}},{{1,0,0}} ,{{0,1,0}} }};
    vector<ll> v = {2,1,0};
    if(n<3) {
        cout <<v[2-n] <<"\n";
        return;
    }
    v = (mat^(n-2)) * v;
    cout <<v[0] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}