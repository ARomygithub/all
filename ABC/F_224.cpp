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
string s;

ll fastexpo(ll a, ll b) {
    ll ret = 1;
    while(b) {
        if(b&1) {
            ret = ret*a%mod;
        }
        a = a*a%mod;
        b >>=1;
    }
    return ret;
}

ll inv(ll a) {
    return fastexpo(a,mod-2);
}

void solve() {
    cin >>s;
    n = s.length();
    ll ans = 0;
    vector<ll> pow10(n,0);
    pow10[0] = 1;
    rep(i,1,n) {
        pow10[i] = pow10[i-1]*10%mod;
    }
    ll iv2 = inv(2ll);
    ll rh = 0;
    rep(i,0,n-1) {
        rh = (rh + pow10[i]*fastexpo(2ll,n-2-i)%mod)%mod;
    }
    rh = (rh + pow10[n-1])%mod;
    rep(i,0,n) {
        if(i>0) {
            ll x = (rh - pow10[n-i]-pow10[n-i-1])%mod;
            x = (x+mod)%mod;
            x = x*iv2%mod;
            rh = (x + pow10[n-i-1])%mod;
        }
        ll temp = fastexpo(2ll,i)*rh%mod;
        temp = temp*(s[i]-'0')%mod;
        // cout <<rh <<"\n";
        // cout <<temp <<"\n";
        ans = (ans+temp)%mod;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}