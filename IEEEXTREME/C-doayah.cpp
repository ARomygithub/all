#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const ll MOD = 998244353;
ll fac[100001], inv[100001];

ll pw(ll b, ll p){
    ll res = 1;
    for(; p; p >>= 1, b *= b, b %= MOD){
        if(p & 1){
            res *= b;
            res %= MOD;
        }
    }
    return res;
}

ll nCk(int n, int k){
    return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

void solve(){
    int N, M; ll X; cin >> N >> M >> X;

    vector<ll> val;
    for(int i = 1; i <= N; ++i){
        ll K, J; cin >> K >> J;
        val.push_back(max((X - J) * K - J, X) % MOD);
    }

    sort(val.begin(), val.end());

    ll answer = 0;
    for(int i = M; i <= N; ++i){
        answer += val[i - 1] * nCk(i - 1, M - 1) % MOD;
        if(answer >= MOD)answer -= MOD;
    }
    answer = answer * pw(nCk(N, M), MOD - 2) % MOD;

    cout << answer;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    fac[0] = inv[0] = 1;
    for(ll i = 1; i <= 100000; ++i){
        fac[i] = i * fac[i - 1] % MOD;
        inv[i] = pw(fac[i], MOD - 2);
    }

    int tc = 1; //cin >> tc;

    while(tc--){
        solve();
    }

    return 0;
}