#include <bits/stdc++.h>

using namespace std;

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const ll mod = 998244353;

vector<vector<ll>> multiply(vector<vector<ll>> a, vector<vector<ll>> b) {
    vector<vector<ll>> c(a.size(), vector<ll>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < a[0].size(); k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return c;
}

vector<vector<ll>> power(vector<vector<ll>> a, ll n) {
    int m = a.size();
    vector<vector<ll>> res(m, vector<ll>(m, 0));
    for(int i = 0; i < m; i++) {
        res[i][i] = 1;
    }

    while(n > 0) {
        if(n % 2 == 1) {
            res = multiply(res, a);
        }
        a = multiply(a, a);
        n /= 2;
    }

    return res;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k, t;
    cin >> n >> k >> t;


    vector<vector<ll>> ml = {
        {(k+1)%mod, 0, (mod-1), 1},
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0}
    };

    vector<vector<ll>> base(4, vector<ll>(1, 0));
    base[3][0] = (n+1)%mod;

    for(int i=2; i>=0; i--) {
        base[i][0] = (base[i+1][0] * ((k+1)%mod)) % mod;
        if(i == 0) {
            base[i][0] = (base[i][0] + (mod - (n)%mod)%mod) % mod;
        }
    }



    // for(int i=0; i<4; i++) {
    //     for(int j=0; j<1; j++) {
    //         cout << base[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    if(t <= 3) {
        cout << (base[3-t][0]%mod + mod - 1)%mod << "\n";
    } else {
        vector<vector<ll>> res = multiply(power(ml, t-3), base);
        ll ans = (res[0][0] + (mod - 1)%mod) % mod;
        cout << ans << "\n";
    }

    return 0;
}