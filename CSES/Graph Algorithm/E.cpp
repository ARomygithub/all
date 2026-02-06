#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    int t; cin >>t;
    while(t--) {
        cin >>n; n++;
        int ans;
        if(n%2==0) {
            ans = 3*n*n-6*n+6;
        } else {
            ans = 3*n*n-3*n+1;
        }
        for(int i=1;i<=(n/2)-1;i++) {
            for(int j=1;j<=(n/2)-1;j++) {
                for(int k=1;k<=(n/2)-1;k++) {
                    if((n-j)*i*k==j*(n-i)*(n-k)) ans -=6;
                }
            }
        }
        cout <<ans <<"\n";
    }
}
