#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e3;
int n, q, a[mxn+1][mxn+1];
string s[mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n >>q;
    for(int i=0;i<n;i++) {
        cin >>s[i];
        for(int j=0;j<n;j++) {
            if(s[i][j]=='*') a[i+1][j+1]++;
            a[i+1][j+1] +=a[i+1][j];
        }
        for(int j=0;j<n;j++) {
            a[i+1][j+1] += a[i][j+1];
        }
    }
    while(q--) {
        int y1, x1, y2, x2; cin >>y1 >>x1 >>y2 >>x2; y1--, x1--;
        cout <<a[y2][x2]-a[y1][x2]-a[y2][x1]+a[y1][x1] <<"\n";
    }
}
