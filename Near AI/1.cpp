#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k,m;
    cin >>k >>m;
    long long ct1, ct2;
    // combinations of event A and B
    ct1 = (1ll*m*m - 1ll*(m-k)*(m-k))*1*1;
    
    // combinations of event A
    ct2 = (1ll*k*k*3) + (1ll*k*(m-k)*2*2);

    double ans = 1.0*ct1/ct2;
    cout <<fixed <<setprecision(11) <<ans <<"\n";
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int tc; cin >>tc;
    while(tc--) {
        solve();
    }
    return 0;
}