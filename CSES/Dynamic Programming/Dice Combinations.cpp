#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 1e6;
int n, k;
ll dp[mxn+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n;
    dp[1]=1;
    for(int i=2; i<7; i++) {
        dp[i]=2*dp[i-1];
    }
    for(int i=7; i<=n; i++) {
        dp[i]=(dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6])%((ll)1e9+7);
    }
    cout <<dp[n];
}
