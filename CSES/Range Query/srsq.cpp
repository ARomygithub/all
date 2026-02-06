#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxn= 2e5, mod=1e9+7;
int n, q, a[mxn];
ll x[mxn+1];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n >>q;
    for(int i=0;i<n;i++) {
        cin >>x[i+1];
        x[i+1]+=x[i];
    }
    while(q--) {
        int a,b; cin >>a >> b;
        cout <<x[b]-x[a-1] <<"\n";
    }
}