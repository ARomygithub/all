#include<bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;

#define rep(i, a, b) for(int i = a; i < (b);i++)
#define per(i, a, b) for(int i= a; i > (b);i++) 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> gcda, gcdb;
    int farthest1a = 1, farthest1b = 1;
    for (int i = 1; i <= n; i++)
    {
        int ga = gcd(i, a);
        int gb = gcd(i, b);
        gcda.push_back(ga);
        gcdb.push_back(gb);
        if (ga == 1)
            farthest1a = i;
        if (gb == 1)
            farthest1b = i;
    }

    ll ans = 0;
    for (int i = 0; i < farthest1a; i++)    
    {
        ans += gcda[i];
    }
    for (int i = 0; i < farthest1b; i++)    
    {
        ans += gcdb[i];
    }
    ans += ( farthest1a + farthest1b - 2 - gcda[farthest1a - 1] - gcdb[farthest1b - 1]);

    int arrrow = n - farthest1a + 1;
    int arrcol = n - farthest1b + 1;
    int arr[arrrow][arrcol];
    for (int i = 0; i < arrrow; i++)
    for (int j = 0; j < arrcol; j++)
    {
        arr[i][j] = gcd(i + farthest1a, a);
        arr[i][j] += gcd(j + farthest1b, b);
    }
    
    // for (int i = 0; i < arrrow; i++)
    // {
    //     for (int j = 0; j < arrcol; j++)
    //     {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // what_is("=================")
    
    int dp[arrrow][arrcol];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = arr[0][0];
    for (int i = 1; i < arrrow; i++)
    {
        dp[i][0] = arr[i][0] + dp[i - 1][0];
    }
    for (int i = 1; i < arrcol; i++)
    {
        dp[0][i] = arr[0][i] + dp[0][i - 1];
    }
    for (int i = 1; i < arrrow; i++)
    {
        for (int j = 1; j < arrcol; j++)
        {
            dp[i][j] = arr[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

        
    // for (int i = 0; i < arrrow; i++)
    // {
    //     for (int j = 0; j < arrcol; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    

    cout << dp[arrrow - 1][arrcol - 1] + ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tc; 
    tc = 1;
    while(tc--) {
        solve();
    }
}