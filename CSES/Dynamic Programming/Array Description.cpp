#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 1e5, mod=1e9+7;
int n, m, a[mxn];
ll dp[mxn][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m;
    for(int i=0; i<n; i++) {
        cin >>a[i];
        --a[i];
    }
    for(int i=0; i<n; i++) {
        if(i) {
            for(int j=0; j<m; j++) {
                dp[i][j]=dp[i-1][j];
                if(j)
                    dp[i][j]+=dp[i-1][j-1];
                if(j<m-1)
                    dp[i][j]+=dp[i-1][j+1];
                dp[i][j]%=mod;
            }
        }
        else {
            for(int j=0; j<m; j++) {
                dp[0][j]=1;
            }
        }
        if(~a[i])
            for(int j=0; j<m; j++)
            if(j^a[i])
            dp[i][j]=0;
    }
    int ans=0;
    for(int i=0; i<m; i++) {
        ans =(ans+dp[n-1][i])%mod;
    }
    cout <<ans;
}
