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

const int mxn=5e3;
const ll mod = 998244353;
int n,k;
int dp[mxn+1];

void solve() {
    cin >>n >>k;
    dp[0] = 1;
    while(n--) {
        char qt; cin >>qt;
        int x; cin >>x;
        if(qt=='+') {
            per(i,k,x-1) {
                dp[i] = (dp[i] + dp[i-x])%mod;
            }
            cout <<dp[k] <<"\n";
        } else {
            rep(i,x,k+1) {
                dp[i] = (dp[i] - dp[i-x] + mod)%mod;
            }
            cout <<dp[k] <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}