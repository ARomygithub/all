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
    dp[0]=0;
    for(int i=1; i<=x; i++) {
        if(i<c[0])
            dp[i]=0;
        else
            dp[i]=b[0];
    }
    for(int j=1; j<n; j++) {
        for(int i=x; i>0; i--) {
            if(i>=c[j])
                dp[i]=max(dp[i],b[j]+dp[i-c[j]]);
        }
    }
    cout <<dp[x];
}
