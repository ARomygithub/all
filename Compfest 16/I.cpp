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

const int mxn=2e5;
const ll mod=998244353;
int n,m,k;

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

ll inv(ll a, ll md=mod) {
    return fastexpo(a,md-2);
}

void solve() {
    cin >>n >>m >>k;
    ll r = n;
    ll ct1 = fastexpo(n-1,k)*inv(fastexpo(n,k))%mod;
    ct1 = ct1*n%mod;
    r = (r - ct1 + mod)%mod;
    ll c = m;
    ll ct2 = fastexpo(m-1,k)*inv(fastexpo(m,k))%mod;
    ct2 = ct2*m%mod;
    c = (c - ct2 + mod)%mod;
    ll ans = (r*m%mod + c*n%mod)%mod;
    ans = (ans - r*c%mod + mod)%mod;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}