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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2500;
const ll mod=998244353;
int n,k,t;

void solve() {
    cin >>n >>k;
    vector<vector<ll>> dp(n+1,vector<ll>(k,1));
    rep(i,1,n+1) {
        rep(j,0,k) {
            dp[i][j] = 0;
            rep(l,0,k-j) {
                int temp = i-(j+1)*(l+1);
                if(temp<0) break;
                dp[i][j] = (dp[i][j]+dp[temp][l])%mod;
            }
        }
    }
    ll ans = 0;
    rep(i,0,k) {
        ans = (ans+dp[n][i])%mod;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}