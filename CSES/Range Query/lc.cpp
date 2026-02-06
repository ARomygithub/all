#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()

const int mxn=1e5;
int n,k;
ll s[mxn+1];
int a[mxn];

void solve() {
    cin >>n >>k;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    ll ans=0;
    s[0] = 0;
    for(int i=0;i<n;i++) {
        int b; cin >>b;
        s[i+1] = s[i];
        if(b==1) {
            ans += a[i];
        } else {
            s[i+1] += a[i];
        }
    }
    ll bonus = 0;
    for(int i=0;i<=n-k;i++) {
        bonus = max(bonus, s[i+k]-s[i]);
    }
    ans += bonus;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
