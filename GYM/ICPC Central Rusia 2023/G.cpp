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
const ll mod = 1e9+7;
int n,k[3];

void solve() {
    cin >>n;
    rep(i,0,3) {
        cin >>k[i];
    }
    vector<ll> ans(n+1,0);
    vector dp(3, vector<ll>(n+1,0));
    ans[1] = 3;
    rep(i,0,3) {
        dp[i][1] = 1;
    }
    rep(j,2,n+1) {
        rep(i,0,3) {
            ll tmp = (ans[j-1] - dp[i][j-1] + mod)%mod;
            if(j-k[i]-1>=0) {
                ll tmp2 = (ans[j-k[i]-1] - dp[i][j-k[i]-1] + mod)%mod;
                tmp = (tmp - tmp2 + mod)%mod;
            }
            if(j-k[i]<=0) {
                tmp = (tmp+1)%mod;
            }
            dp[i][j] = tmp;
            ans[j] = (ans[j] + tmp)%mod;
            dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
        }
        ans[j] = (ans[j] + ans[j-1])%mod;
    }
    cout <<(ans[n]-ans[n-1]+mod)%mod <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}