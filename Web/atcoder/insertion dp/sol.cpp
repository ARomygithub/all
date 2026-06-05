#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

#define rep(i, x) for(int i = 0; i < (x); i++)
using ll = long long;
using mint = atcoder::modint998244353;

int main() {
    int n, k;
    cin >> n >> k;
    // aの末尾より大きい要素,bの末尾より大きい要素,類似度
    vector dp(k + 1, vector(n, vector(n, mint(0))));
    vector ndp(k + 1, vector(n, vector(n, mint(0))));
    rep(i, n) rep(j, n) dp[0][i][j] = 1;
    vector ct(k + 1, vector(n + 1, vector(n + 1, mint(0))));
    for(int t = 1; t < n; t++) {
        rep(s, min(t, k) + 1) {
            auto &tb = ct[s];
            rep(i, n + 1 - t) {
                rep(j, n + 1 - t) {
                    tb[i + 1][j + 1] =
                        tb[i][j + 1] + tb[i + 1][j] - tb[i][j] + dp[s][i][j];
                }
            }
        }
        auto get = [&](int id, int lx, int rx, int ly, int ry) -> mint {
            if(lx >= rx or ly >= ry) return 0;
            return ct[id][rx][ry] - ct[id][lx][ry] - ct[id][rx][ly] + ct[id][lx][ly];
        };
        rep(ns, min(t, k) + 1) {
            rep(i, n - t) {
                rep(j, n - t) {
                    ndp[ns][i][j] = get(ns, 0, i + 1, j + 1, n + 1 - t) + get(ns, i + 1, n + 1 - t, 0, j + 1) + (ns ? get(ns - 1, 0, i + 1, 0, j + 1) + get(ns - 1, i + 1, n + 1 - t, j + 1, n + 1 - t) : 0);
                }
            }
        }
        swap(dp, ndp);
    }
    cout << dp.back()[0][0].val() << endl;
}