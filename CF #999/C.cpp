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
const ll mod = 998244353;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<ll> dp(n,0);
    rep(i,0,n) {
        if(i==0) {
            if(a[i]==0) {
                dp[i] = 1;
            }
        } else if(i==1) {
            if(a[i-1]==a[i] && a[i]==0) {
                dp[i]++;
            }
            if(a[i]==1) {
                dp[i]++;
            }
        } else {
            if(a[i-1]==a[i]) {
                dp[i] = (dp[i] + dp[i-1])%mod;
            }
            if(a[i]==a[i-2]+1) {
                dp[i] = (dp[i] + dp[i-2])%mod;
            }
        }
    }
    ll ans = 0;
    if(n>1) {
        ans = (ans + dp[n-2])%mod;
    } else {
        ans = (ans + 1)%mod;
    }
    ans = (ans + dp[n-1])%mod;
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