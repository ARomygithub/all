#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 10, mxa=1e6;
int n, m, a[mxn], ten[mxa];



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m;
    for(int i=0; i<n; i++) {
        cin >>a[i];
    }
    ten[0]=1;
    for(int j=1; j<mxa; j++) {
        ten[j]=(10*ten[j-1])%m;
    }

}
