#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2e5, mod=1e9+7;
int n,q, t[30][mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>q;
    for(int i=0;i<n;i++) {
        cin >>t[0][i]; t[0][i]--;
    }
    for(int j=1;j<30;j++)
        for(int i=0;i<n;i++) {
            t[j][i]=t[j-1][t[j-1][i]];
        }
    while(q--) {
        int x,k; cin >>x >>k; x--;
        for(int i=0;i<30;i++) {
            if(k>>i&1) {
                x = t[i][x];
            }
        }
        cout <<x+1 <<"\n";
    }
}