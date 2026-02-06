#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxn=1e5;
ll n;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >>t;
    while(t--) {
        cin >>n;
        ll a[n];
        for(int i=0;i<n;i++) {
            cin >>a[i];
        }
        sort(a,a+n);
        ll ans=a[n-1];
        for(ll i=n-2;i>=0;i--) {
            ans +=(a[i]-a[i+1])*(n-i-1)*(i+1);
        }
        cout <<ans <<"\n";
    }
}   