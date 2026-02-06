#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 1e6, mod=1e9+7;
int n;
int dp[mxn+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n;
    dp[0]=0;
    for(int i=1; i<=n; i++) {
        dp[i]=1e6;
        int i2=i;
        while(i2) {
            dp[i]=min(dp[i],dp[i-i2%10]+1);
            i2 /=10;
        }
    }
    cout <<dp[n];
}
