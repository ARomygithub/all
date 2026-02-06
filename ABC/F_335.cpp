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

const int mxn=2e5,sp=2e7;
const ll mod=998244353;
int n;
int a[mxn], dp[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    int sq=min(sp/n,n);
    vector<vector<int>> dp2(sq+1);
    rep(i,1,sq+1) {
        dp2[i].resize(i,0);
    }
    per(i,n-1,-1) {
        dp[i] = 1;
        if(a[i]>sq) {
            for(int j=i+a[i];j<n;j+=a[i]) {
                dp[i] = (dp[i]+dp[j])%mod;
            }
        } else {
            dp[i] = (dp[i]+dp2[a[i]][i%a[i]]);
        }
        rep(j,1,sq+1) {
            dp2[j][i%j] = (dp2[j][i%j]+dp[i])%mod;
        }
    }
    cout <<dp[0] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}