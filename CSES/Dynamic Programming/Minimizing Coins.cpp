#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 1e6;
int n, x, a[mxn];
int dp[mxn+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>x;
    for(int i=0; i<n; i++) {
        cin >>a[i];
    }
    dp[0]=0;
    for(int i=1; i<=x; i++) {
        dp[i]=1e9;
        for(int j=0; j<n; j++) {
            if(i-a[j]>=0)
                dp[i]=min(dp[i],1+dp[i-a[j]]);
        }
    }
    if(dp[x]>=1e9)
        cout <<"-1";
    else
        cout <<dp[x];
}
