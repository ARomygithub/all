#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b);i++)
#define per(i, a, b) for(int i= a; i > (b);i--) 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

void solve() {
    int n; cin >> n;
    int arr[n];
    rep(i, 0, n) cin >> arr[i];
    int last1[32][n];
    for (int k = 0; k < 32; k++)
    for (int i = 0; i < n; i++)
    {
        last1[k][i] = n;
        short b = 1 & (arr[i] >> k);
        if (b) last1[k][i] = i; 
        else if (i) last1[k][i] = last1[k][i - 1];
    }

    int tree[2 * n];
    for (int i = 0; i < 2*n; i++) tree[i + n] = 0;

    auto update = [&](int x, int pos)
    {
        pos = pos + n;
        while (pos) tree[pos] += x, pos = pos / 2;
    };
    auto query = [&](int l, int r) {
        l = l + n;
        r = r + n;
        ll ans;
        while (l <= r)
        {
            if (l & 1) 
            {
                ans += tree[l];
                l++;
            }
            if (not(r & 1))
            {
                ans += tree[r];
                r--;
            }
        }
        return ans;
    };
    int dp[n] = {0};
    for (int i = 0; i < n; i++)
    {
        int mn_last = n;
        for (int k = 0; k < 32; k++)
        {
            if (!last1[k][i])
            {
                mn_last = min(mn_last, last[k][i]);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}