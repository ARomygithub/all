#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxp=110,mxn=105;
int n;
ar<int,2> ct[mxp][mxp];

void solve() {
    cin >>n;
    int total=0;
    for(int i=0;i<n;i++) {
        int p,h,d; cin >>p >>h >>d; p--,h--;
        ct[p][h][0]++, ct[p][h][1] +=d;
        total+=d;
    }
    vector<vector<int>> dp(mxp,vector<int>(mxp,0));
    for(int i=mxp-1;i>=0;i--) {
        for(int j=mxp-1;j>=0;j--) {
            // i,j diambil
            int temp = ct[i][j][1];
            if(i+1<mxp && j+1<mxp) {
                temp += dp[i+1][j+1];
            }
            max_self(dp[i][j],temp);
            // i,j ga diambil
            if(i+1<mxp) {
                max_self(dp[i][j],dp[i+1][j]);
            }
            if(j+1<mxp) {
                max_self(dp[i][j],dp[i][j+1]);
            }
        }
    }
    cout <<total-dp[0][0] <<"\n"; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
