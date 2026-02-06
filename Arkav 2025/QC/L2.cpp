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

const int mxn=1e6;
const ll mod = 998244353;
int n,m;

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

ll inv(ll a) {
    return fastexpo(a, mod-2);
}

void solve() {
    cin >>n >>m;
    vector<ll> r(n), b(m);
    rep(i,0,n) {
        cin >>r[i];
    }
    rep(i,0,m) {
        cin >>b[i];
    }
    ll sr=0, sb=0;
    rep(i,0,n) {
        sr = (sr + r[i])%mod;
    }
    sr = sr*m%mod;
    rep(i,0,m) {
        sb = (sb + b[i])%mod;
    }
    sb = sb*n%mod;
    ll sm = (sr+sb)%mod;
    ll ct = fastexpo(n,m-1)*fastexpo(m,n-1)%mod;
    sm = sm*ct%mod;
    sm = sm*(n+m-1)%mod;
    sm = sm*inv(n)%mod;
    sm = sm*inv(m)%mod;
    cout <<sm <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}