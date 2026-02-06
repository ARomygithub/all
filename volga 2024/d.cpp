#include<bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;

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
        last1[k][i] = -1;
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
        ll ans = 0;
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
            l /= 2;
            r /= 2;
        }
        return ans;
    };
    
    for (int i = 0; i < n; i++)
    {

        for (int k = 0; k < 3; k++)
        {
            cout << last1[i][k] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    
    int dp[n] = {0};
    int seen1[32] = {0};
    for (int i = 0; i < n; i++)
    {
        int mn_last = i;
        for (int k = 31; k >= 0; k--)
        {
            short b = 1 & (arr[i] >> k);
            if (b) seen1[k] = 1;            
            if (seen1[k] and !b)
            {
                mn_last = min(mn_last, last1[k][i]);
            }
        }
        
        what_is(i)
        what_is(mn_last)
        // partition [mn_last..n] sehingga terambil dp[mn_last - 1]
        // kalo -1 berarti gbs valid.
        if (mn_last == -1) continue;
        // query sum [0..mn_last - 1]

        if (mn_last == 0) dp[i] = 1;
        else dp[i] = 1 + query(0, mn_last - 1);
        update(dp[i], i);

        what_is(dp[i])
    }

    cout << dp[n - 1] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}