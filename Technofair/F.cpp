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

const int mxn=2e3;
const ll mod=1e9+7;
int n,k;

void solve() {
    cin >>n >>k;
    vector<ll> dp(n+1, 1ll);
    rep(i,2,k+1) {
        vector<ll> dp_new(n+1,0ll);
        rep(j,1,n+1) {
            for(int jj=j;jj<=n;jj+=j) {
                dp_new[jj] = (dp_new[jj] + dp[j])%mod;
            }
        }
        dp.swap(dp_new);
    }
    ll ans = 0ll;
    rep(i,1,n+1) {
        ans = (ans + dp[i])%mod;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}