#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e2 + 5;
const int W = 1e5 + 5;

int n, w;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<vector<ll>> dp(2,vector<ll>(w+1,0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            dp[1][j] = dp[0][j];
            if (a[i] <= j) {
                dp[1][j] = max(dp[1][j], dp[0][j - a[i]] + b[i]);
            }
        }
        dp[1].swap(dp[0]);
    }
    cout << dp[0][w] << '\n';

    return 0;
}