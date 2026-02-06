#include <bits/stdc++.h>
using namespace std;

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

const int mxn=2e2,mxw=5e2;
int n,c,t;
int wf[mxn][2];
int dp[mxn][mxw+1];

void solve() {
    cin >>c >>n;
    for(int i=0;i<n;i++) {
        cin >>wf[i][0] >>wf[i][1];
    }
    for(int i=wf[0][0];i<=c;i++) {
        dp[0][i] = wf[0][1];
    }
    for(int i=1;i<n;i++) {
        for(int j=0;j<=c;j++) {
            dp[i][j] = dp[i-1][j];
            if(j>=wf[i][0]) {
                max_self(dp[i][j], dp[i-1][j-wf[i][0]]+wf[i][1]);
            }
        }
    }
    int ans=dp[n-1][c];
    // for(int i=0;i<=c;i++) {
    //     max_self(ans, dp[n-1][i]);
    // }
    cout <<ans <<"\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<=c;j++) {
            dp[i][j] = 0;
        }
    }
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