#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e6, mod=1000696969, nb=1, B[nb]={69};
int n;
string s;
ll pB[nb][mxn+1], h[nb][mxn+1];

vector<ll> hs(int l, int r) {
    vector<ll> a;
    for(int i=0;i<nb;i++) {
        a.push_back(h[i][r+1]-h[i][l]*pB[i][r-l+1]%mod);
        if(a.back()<0) a.back() +=mod;
    }
    return a;
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
    for(int i=1;i<n;i++) {
        if(hs(0,i-1)==hs(n-i,n-1)) cout <<i <<" ";
    }
}
