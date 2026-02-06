#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()

const int mxn=1e5;
int n,q;
ll s[mxn+1];

void solve() {
    cin >>n;
    s[0]=0;
    for(int i=0;i<n;i++) {
        ll x; cin >>x;
        s[i+1] = s[i]+x;
    }
    cin >>q;
    while(q--) {
        int a,b; cin >>a >>b;
        cout <<s[b+1]-s[a] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
