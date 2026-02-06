#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 1e6, mod=1e9+7;
int n;
string s[1000];
int dp[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n;
    dp[0][0]=1;
    for(int i=0; i<n; i++) {
        cin >>s[i];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(s[i][j]=='*')
                dp[i][j]=0;
            else {
            if(i)
                dp[i][j]+=dp[i-1][j];
            if(j)
                dp[i][j]+=dp[i][j-1];
            dp[i][j]%=mod;
            }
        }
    }
    cout <<dp[n-1][n-1];
}
