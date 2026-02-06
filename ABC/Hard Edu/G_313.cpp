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

const int mxn=2e5;
const ll mod = 998244353;
int n;
int a[mxn];

ll f(ll ai, ll bi, ll ci, ll ni) {
    assert(ni*(ni+1)%mod == (ni)%mod*(ni+1)%mod);
    ll ret = ni*(ni+1)/2%mod*(ai/ci)%mod;
    ret = (ret + (ni+1)%mod*(bi/ci)%mod)%mod;
    ai %= ci; bi %= ci;
    if(ai==0ll) {
        return ret;
    }
    ll mi = (ai*ni + bi)/ci;
    if(mi==0ll) {
        return ret;
    }
    ret = (ret + (mi%mod)*ni%mod)%mod;
    ret = (ret - f(ci,ci-bi-1,ai,mi-1) + mod)%mod;
    return ret; 
}

// long long FloorSumAP(long long a, long long b, long long c, long long n){
//     // cout <<"TEs\n";
//   if(!a) return (b / c) * (n + 1);
//   if(a >= c or b >= c) return ( ( n * (n + 1) ) / 2) * (a / c) + (n + 1) * (b / c) + FloorSumAP(a % c, b % c, c, n);
//   long long m = (a * n + b) / c;
//   return m * n - FloorSumAP(c, c - b - 1, a, m - 1);
// }

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    sort(a,a+n);
    ll ans = (a[0]+1)%mod;
    int idx = 0;
    int ls = 0;
    ll x = 0;
    while(idx<n) {
        int awl = idx;
        while(idx+1<n && a[idx+1]==a[idx]) {
            idx++;
        }
        int dif = a[idx]-ls;
        if(a[idx]!=a[0]) {
            // cout <<n-awl <<" " <<x <<" " <<n <<" " <<dif <<endl;
            ans = (ans + f(n-awl,x,n,dif))%mod;
            // ans = (ans + FloorSumAP(n-awl, x, n, dif)%mod)%mod;
            ans = (ans - (x/n) + mod)%mod;
            ans = (ans + dif)%mod;
        }
        x += 1ll*(n-awl)*dif; 
        ls = a[idx];
        idx++;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}