#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5;
int n, e0[101], e1[101];
bool a[mxn];
int dp[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    for(int i=0;i<n;i++) {
        int x; cin >>x;
        if(a[i]) {
            e1[x]++;
        } else {
            e0[x]++;
        }
    }

}
