#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e3;
int n,q, ft[mxn+1],mx[mxn+1];

void upd(int i2, int j2, int x) {
    for(int i=i2;i<=n;i+=i&-i) {
        for(int j=j2;j<=n;j+=j&-j) {
            ft[i][j] +=x;
        }
    }
}

int qry(int i2, int j2) {
    int r=0;
    for(int i=i2;i;i -=i&-i) {
        for(int j=j2;j;j-=j&-j) {
            r +=ft[i][j];
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n;
    
}
