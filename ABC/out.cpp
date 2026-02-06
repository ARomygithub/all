#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll INF = (ll)(1e18) + 1;
    ll INF2 = (ll)(1e18) + 69;
  cout << INF << endl; // --> 1000000000000000000

  ll x = INF + 1;
  cout << x << endl; // --> 1000000000000000001

  cout << INF2 << endl; // --> 1000000000000000128
  return 0;
}