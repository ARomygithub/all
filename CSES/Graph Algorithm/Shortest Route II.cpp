#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=500;
int n,m,q;
ll d[mxn][mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m >>q;
    memset(d,0x3f,sizeof(d));
    for(int i=0;i<m;i++) {
        ll a,b,c;
        cin >>a >>b >>c; --a, --b;
        d[a][b]=min(d[a][b],c);
        d[b][a]=min(d[b][a],c);
    }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
    for(int i=0;i<n;i++)
        d[i][i]=0;
    while(q--) {
        int a,b;
        cin >>a >>b; a--, b--;
        cout <<(d[a][b]>=1e18?-1:d[a][b]) <<"\n";
    }
}   