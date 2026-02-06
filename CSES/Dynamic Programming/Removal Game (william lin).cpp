#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 5e3, mod=1e9+7;
int n, a[mxn];
ar<ll,2> dp[mxn][mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n;
    for(int i=0; i<n; i++) {
        cin >>a[i];
    }
    for(int i=n-1; i>=0; i--)
    for(int j=i; j<n; j++) {
        ar<ll,2> tr;
        if(j==i) {
            tr={a[i],0};
        }
        else {
            if(dp[i+1][j][1]+a[i]>dp[i][j-1][1]+a[j])
            tr={dp[i+1][j][1]+a[i],dp[i+1][j][0]};
            else
            tr={dp[i][j-1][1]+a[j],dp[i][j-1][0]};
        }
        dp[i][j]=tr;
    }
    cout <<dp[0][n-1][0];
}
