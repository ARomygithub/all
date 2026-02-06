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

const int mxn=1e5,mxa=1e6;
const ll mod = 1e9+7;
int n,t;
ll fct[mxa+1];

ll fastexpo(ll a, ll b) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = ret*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ret;
}

void solve() {
    cin >>n;
    ll pw = (fct[n]-1+(mod-1))%(mod-1);
    ll ans = fastexpo(8,pw)*9%mod;
    ll t1 = fastexpo(4,pw)*5%mod;
    ll t2 = fastexpo(3,pw)*4%mod;
    ans = (ans - t1 + mod)%mod;
    ans = (ans - t2 +mod)%mod;
    cout <<ans <<"\n";
}

void init() {
    fct[0] = 1;
    rep(i,1,mxa+1) {
        fct[i] = fct[i-1]*(i)%(mod-1); 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init();
    while(t--) {
        solve();
    }
}