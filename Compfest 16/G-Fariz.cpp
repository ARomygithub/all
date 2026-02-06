#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second

const int mod = 1e9+7;
const int N = 2e5 + 69;
int cnt = 0;
int n;

void solve() {
  int n, m;
  cin >> n >> m;

  int arr[n+5], brr[m+5];

  int sum1 = 0, sum2 = 0;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    sum1 += arr[i];
  }

  for (int i = 1; i <= m; i++) {
    cin >> brr[i];
    sum2 += brr[i];
  }

  bitset<2069> dp[2069];

  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = sum1; j >= 0; j--) {
      for (int k = sum1; k >= 0; k--) {
        if (j >= arr[i] && dp[j-arr[i]][k]) dp[j][k] = 1;
        if (k >= arr[i] && dp[j][k-arr[i]]) dp[j][k] = 1;
      }
    }
  }

  int ans = 1e9;
  for (int i = 0; i <= sum1; i++) {
    for (int j = 0; j <= sum1; j++) {
      if (dp[i][j]) {
        ans = min(ans, max(sum1 - i - j, sum2 + max(i, j)));
      }
    }
  }

  cout << ans << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc = 1;
  //cin >> tc;

  while (tc--) {
    solve();
  }
}