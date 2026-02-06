#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<(b);i++)
#define per(i,a,b) for(int i=a;i>(b);i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

void solve() {
    int n; cin >> n;
    string s;
    cin >> s;
    pair<int,int> dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            dp[i][i] = {1,1};
        }
        else dp[i][i] = {-1,-1};
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            dp[i][i + 1] = {-1,1};
        }
        else if (s[i] == '(')
        {
            dp[i][i + 1] = {1,1};
        }
        else dp[i][i + 1] = {-1,1};
    }
    for (int k = 3; k < n + 1; k++)
    {
        for (int l = 0; l + k - 1 < n; l++)
        {
            char li1 = s[l];
            char li2 = s[l + 1];
            char ri1 = s[l + k - 1];
            char ri2 = s[l + k - 2];
            // M takes left
            pair<int,
        }
    }

}

int  main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; 
    cin >>t;
    while(t--) {
        solve();
    }
}