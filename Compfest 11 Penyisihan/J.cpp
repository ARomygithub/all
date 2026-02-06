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
int n,m;
int a[mxn],b[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,m) {
        cin >>b[i];
    }
    vector dp(m,vector<ll>(2,0));
    dp[0][0] = 1;
    rep(i,0,n) {
        vector dp_new(m, vector<ll>(2,0));
        rep(j,0,m) {
            if(dp[j][0]) {
                if(a[i]==b[j]) {
                    dp_new[j][1] = (dp_new[j][1] + dp[j][0])%mod;
                } else if(a[i]<b[j]) {
                    dp_new[j][0] = (dp_new[j][0] + dp[j][0])%mod;
                } else {
                    dp_new[j][0] = 0;
                }
            }
            if(dp[j][1]) {
                if(a[i]==b[j]) {
                    dp_new[j][1] = (dp_new[j][1]+dp[j][1])%mod;
                } else if(a[i]<b[j]) {
                    dp_new[j][1] = (dp_new[j][1] + dp[j][1])%mod;
                } else {
                    dp_new[j][1] = 0;
                }
                if(j+1<m && a[i]<=b[j+1]) {
                    if(a[i]<b[j+1]) {
                        dp_new[j+1][0] = (dp_new[j+1][0] + dp[j][1])%mod;
                    } else {
                        dp_new[j+1][1] = (dp_new[j+1][1] + dp[j][1])%mod;
                    }
                }
            }
        }
        dp.swap(dp_new);
    }
    cout <<dp[m-1][1] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}