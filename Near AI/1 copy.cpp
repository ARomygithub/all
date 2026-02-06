#include <bits/stdc++.h>
using namespace std;

void solve() {
    long double k,m;
    cin >>k >>m;
    long double ct1, ct2;
    // combinations of event A and B
    // ct1 = (1ll*m*(m) - 1ll*(m-k)*(m-k))*1*1;
    ct1 = 1.0L*m*2 -k;
    
    // combinations of event A
    // ct2 = (1ll*k*(k)*3) + (1ll*k*(m-k)*2*2);
    ct2 = 1.0L*m*4 - k;
    long double ans = 1.0L*ct1/ct2;
    cout <<fixed <<setprecision(15) <<ans <<"\n";
}

int main() {
    int tc; cin >>tc;
    while(tc--) {
        solve();
    }
    return 0;
}