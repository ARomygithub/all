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

using pic = pair<int,char>;
const int mxn=1e5;
const ll mod=998244353;
int n,m;
pic pc[mxn];

template<class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M& m) const {
        M a;
        rep(i,0,N) rep(j,0,N)
            rep(k,0,N) a.d[i][j] = (a.d[i][j] + d[i][k]*m.d[k][j]%mod) %mod;
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

ll calc(vector<pic>& pci, int len) {
    Matrix<ll,3> mat;
    // mat.d = {{1,0,1}, {1,0,0}, {0,1,1}};
    mat.d = {{ {{1,0,1}}, {{1,0,0}}, {{0,1,1}} }};
    vector<ll> v = {1,0,0};
    int ls = 0;
    rep(i,0,sz(pci)) {
        auto [p,c] = pci[i];
        if(p-ls>1) {
            int pw = p-ls-1;
            v = (mat^pw) * v;
        }
        if(c=='B') {
            v = {0, v[0], (v[1]+v[2])%mod};
        } else {
            v = {(v[0]+v[2])%mod, 0, 0};
        }
        ls = p;
    }
    if(len-ls>0) {
        int pw = len-ls;
        v = (mat^pw) * v;
    }
    return (v[0]+v[2])%mod;
}

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        cin >>pc[i].fi >>pc[i].se;
    }
    sort(pc,pc+m);
    ll ans = 1;
    {
        int len = (n+1)/2;
        vector<pic> pci;
        rep(i,0,m) {
            if(pc[i].fi%2) {
                auto pcc = pc[i];
                pcc.fi = (pcc.fi+1)/2;
                pci.push_back(pcc);
            }
        }
        ans = ans*calc(pci, len)%mod;
    }
    {
        int len = n/2;
        vector<pic> pci;
        rep(i,0,m) {
            if((pc[i].fi%2)==0) {
                auto pcc = pc[i];
                pcc.fi = (pcc.fi)/2;
                pci.push_back(pcc);
            }
        }
        ans = ans*calc(pci,len)%mod;
    }
    cout << ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}