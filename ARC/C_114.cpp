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

const int mxn=5e3;
const ll mod=998244353;
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

void solve() {
    cin >>n >>m;
    ll ans = 0ll;
    vector expo(m+1, vector<ll>(n+1,0ll));
    expo[0][0] = 1;
    rep(i,1,m+1) {
        expo[i][0] = 1;
        rep(j,1,n+1) {
            expo[i][j] = expo[i][j-1]*i%mod;
        }
    }
    rep(len,1,n+1) {
        rep(val,1,m+1) {
            ll cur = (expo[m-val+1][len] - expo[m-val][len] + mod)%mod;
            ll temp = cur;
            if(len<n) {
                temp = temp*(val-1)%mod;
                temp = temp*expo[m][n-len-1]%mod;
                temp = temp*2ll%mod;
            }
            ans = (ans + temp)%mod;
            if(len<=n-2) {
                ll temp2 = cur*fastexpo(val-1,2)%mod;
                temp2 = temp2*expo[m][n-len-2]%mod;
                temp2 = temp2*(n-len-1)%mod;
                ans = (ans + temp2)%mod;
            }
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}