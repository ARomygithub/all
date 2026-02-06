#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 1e3;
int n, a[mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n;
    for(int i=0; i<n; i++) {
        cin >>a[i];
    }
    for(int i=n-1; i>=0; i--) {
        cout <<a[i] <<" ";
    }
}
