#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5;
int n,m;

struct st {
    int s, t;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    cin >>n >>m;
    st a[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >>a[i][j].s;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >>a[i][j].t;
        }
    }
    if(n>m) {
        
    } else {

    }
}
