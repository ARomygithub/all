#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 1e5, mod=1e9+7;
int n, x, c[1000], b[1000];
int dp[mxn+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>x;
    for(int i=0; i<n; i++) {
        cin >>c[i];
    }
    for(int i=0; i<n; i++) {
        cin >>b[i];
    }
    for(int j=0; j<n; j++) {
        for (int i=x; i>=c[j]; i--) {
            dp[i]=max(dp[i],b[j]+dp[i-c[j]]);
        }
    }
    cout <<dp[x];
}
