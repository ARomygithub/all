#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 5e3, mod=1e9+7;
int n, a[mxn];
ll dp[mxn][mxn+1], s[mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n;
    for(int i=0; i<n; i++) {
        cin >>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int l=1; l<=n; l++)
    for(int m=0; m<=n-l; m++) {
        if(l==1) {
            dp[m][1]=a[m];
            continue;
        }
        dp[m][l]=max(a[m]+s[m+l-1]-s[m]-dp[m+1][l-1],a[m+l-1]+s[m+l-2]-s[m-1]-dp[m][l-1]);
    }
    cout <<dp[0][n];
}
