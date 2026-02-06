#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e6;
int n,m, dp[mxn], a[mxn];
bool ok;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    cin >>n >>m;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        if(a[i]>=0) ok=true;
    }
    if(!ok) {
        sort(a,a+n);
        cout <<a[n-1];
        return 0;
    }
    dp[0] = max(dp[0],a[0]);
    for(int i=1;i<m;i++) {
        dp[i] = max(dp[i-1],a[i]);
    }
    for(int i=m;i<n;i++) {
        dp[i]=max(dp[i-1],a[i]+dp[i-m]);
    }
    cout <<dp[n-1];

}
