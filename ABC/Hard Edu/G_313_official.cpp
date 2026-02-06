#include <bits/stdc++.h>
using namespace std;

#include "atcoder/math.hpp"
#include "atcoder/modint.hpp"
using mint = atcoder::modint998244353;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for(auto&x : A) cin >> x;
  sort(begin(A), end(A));
  ll s = A[0] * N;
  mint ans = A[0] + 1;
  for (int i = 1; i < N; i++) {
    ll L = A[i - 1];
    ll R = A[i];
    ll a = N - i;
    ll b = s - L * (N - i);
    ll m = N;
    ll cur = 0;
    cur += atcoder::floor_sum(R + 1, m, a, b);
    cur -= atcoder::floor_sum(L + 1, m, a, b);
    cur += R - L;
    ans += cur;
    s += (R - L) * (N - i);
  }
  cout << ans.val() << "\n";
}
