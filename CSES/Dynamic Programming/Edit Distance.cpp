#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 5e2, mod=1e9+7;
int n, m;
int dp[mxn+1][mxn+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m;
    if(n>m)
        swap(n,m);
    int k=n+m;
    for(int i=2; i<=k; i++) {
        for(int j=1; j<=i/2; j++) {
            dp[j][i-j]=1e6;
            for(int l=1; l<=(i-j)/2; l++) {
                dp[j][i-j]=min(dp[j][i-j],1+dp[j][l]+dp[j][i-j-l);
            }
            if(j==i-j)
                dp[j][i-j]=0;
            dp[i-j][j]=dp[j][i-j]
        }
    }
    cout <<dp[n][m];
}
