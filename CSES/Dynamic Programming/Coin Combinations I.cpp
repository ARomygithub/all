#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 1e6, mod=1e9+7;
int n, x, a[100];
int dp[mxn+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>x;
    for(int i=0; i<n; i++) {
        cin >>a[i];
    }
    dp[0]=1;
    for(int i=1; i<=x; i++) {
        dp[i]=0;
        for(int j=0; j<n; j++) {
           if(i>=a[j])
           dp[i]=(dp[i]+dp[i-a[j]])%(mod);
        }
    }
    cout <<dp[x];
}
