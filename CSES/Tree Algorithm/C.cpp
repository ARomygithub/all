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
        cin >>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >>v[i];
        if(v[n-1]==0) {
            for(int j=1;j<=n+1;j++) {
                cout <<j <<" ";
            }
        } else {
            if(v[0]==1) {
                cout <<n+1 <<" ";
                for(int j=1;j<=n;j++) {
                    cout <<j <<" ";
                }
            } else {
                int j=1;
                while(v[j-1]==0) {
                    cout <<j <<" ";
                    j++;
                }
                cout <<n+1 <<" ";
                while(j<=n) {
                    cout <<j <<" ";
                    j++;
                }
            }
        }
        cout <<"\n";
    }
}
