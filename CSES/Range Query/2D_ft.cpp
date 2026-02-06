#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e3;
int n,q, ft[mxn+1][mxn+1];
string s[mxn];

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
    cin >>n >>q;
    for(int i=0;i<n;i++) {
        cin >>s[i];
        for(int j=0;j<n;j++) {
            if(s[i][j]=='*') upd(i+1,j+1,1);
        }
    }
    while(q--) {
        int c; cin >>c;
        if(c==1) {
            int y,x; cin >>y >>x; y--,x--;
            upd(y+1,x+1,s[y][x]=='*'?-1:1);
            if(s[y][x]=='*') {
                s[y][x]='.';
            } else {
                s[y][x]='*';
            }
        } else {
            int y1,x1,y2,x2; cin >>y1 >>x1 >>y2 >>x2;
            cout <<qry(y2,x2) -qry(y1-1,x2) - qry(y2,x1-1) + qry(y1-1,x1-1) <<"\n";
        }
    }
}
