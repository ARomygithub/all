#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e6, mod=1000696969, nb=1, B[nb]={69};
int n;
string s;
ll pB[nb][mxn+1], h[nb][mxn+1];

ll hs(int l, int r) {
    ll x = h[0][r+1]-h[0][l]*pB[0][r-l+1]%mod;
    if(x<0) x+=mod;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    cin >>s;
    n = s.size();
    for(int i=0;i<nb;i++) {
        pB[i][0]=1;
        for(int j=1;j<=n;j++)
            pB[i][j]=pB[i][j-1]*B[i]%mod;
        for(int j=1;j<=n;j++) {
            h[i][j]=(h[i][j-1]*B[i]+s[j-1]-'a'+1)%mod;
        }
    }
    for(int i=1;i<=n;i++) {
        ll a=hs(0,i-1);
        bool ok=true;
        for(int j=i;j<n&&ok;j+=i) {
            if(j+i<n) {
                ok &= a==hs(j,j+i-1);
            } else {
                ok &= hs(j,n-1)==hs(0,n-1-j);
            }
        }
        if(ok) cout <<i <<" ";
    }
}
