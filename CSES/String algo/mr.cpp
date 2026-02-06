#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2e6, mod=1000696969, nb=1, B[nb]={69};
int n,n1;
string s, t;
ll pB[nb][mxn+1], h[nb][mxn+1];

ll hs(int l, int r) {
    ll x = h[0][r+1]-h[0][l]*pB[0][r-l+1]%mod;
    if(x<0) x+=mod;
    return x;
}

bool low(int a, int b) {
    int l1=0, r1=n1; int f=0;
    while(l1<=r1) {
        int mid=(l1+r1)/2;
        if(mid==0 || hs(a,a+mid-1)==hs(b,b+mid-1)) {
            f=mid;
            l1=mid+1;
        } else {
            r1=mid-1;
        }
    }
    if(f<n1 && t[a+f]-t[b+f]<0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    cin >>s;
    t = s+s;
    n = t.size();
    n1 =n/2;
    for(int i=0;i<nb;i++) {
        pB[i][0]=1;
        for(int j=1;j<=n;j++)
            pB[i][j]=pB[i][j-1]*B[i]%mod;
        for(int j=1;j<=n;j++) {
            h[i][j]=(h[i][j-1]*B[i]+t[j-1]-'a'+1)%mod;
        }
    }
    int ans=0;
    for(int i=1;i<n1;i++) {
        if(low(i,ans)) {
            ans=i;
        }
    }
    for(int i=ans;i<ans+n1;i++) {
        cout <<t[i];
    }
}
