#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const ll mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const int mxn = 1e9, mxt=1e3;
int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k, t;
    cin >> n >> k >> t;
    // n = (rng()%mxn)+1;
    // k = (rng()%mxn)+1;
    // t = (rng()%mxt)+1;
    cout <<n <<" " <<k <<" " <<t <<endl;
    vector<ll> tes(4,1);
    tes[3] = (n+1)%mod;
    for(ll i=1; i<=t;i++) {
        vector<ll> tes_new(4,1);
        tes_new[3] = ((tes[3]*(k+1)%mod) - ((tes[1]-tes[0]+mod)%mod) + mod)%mod;
        // cout <<tes_new[3] <<endl;
        rep(j,0,3) {
            tes_new[j] = tes[j+1];
        }
        tes.swap(tes_new);
    }
    tes[3] = (tes[3] + mod-1)%mod;


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
            base[i][0] = (base[i][0] + mod - (n)%mod) % mod;
        }
    }



    // for(int i=0; i<4; i++) {
    //     for(int j=0; j<1; j++) {
    //         cout << base[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    if(t <= 3) {
        cout << (base[3-t][0]%mod + mod - 1)%mod << endl;
        cout <<tes[3] <<endl;
        assert(((base[3-t][0]%mod + mod - 1)%mod) == tes[3]);
    } else {
        vector<vector<ll>> res = power(ml, t-3);
        res = multiply(res, base);
        ll ans = (res[0][0]%mod + mod - 1) % mod;
        cout << ans << endl;
        cout <<tes[3] <<endl;
        assert(ans==tes[3]);
    }

    return 0;
}