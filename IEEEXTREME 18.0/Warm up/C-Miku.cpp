#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>
#define debug(x)    cout << #x << " : " << x << endl;

// const int MOD = 1000000007;
const int MOD = 998244353;
const int NMAX = 100005;
vi cnt(NMAX, 0);
vi val(NMAX, 0);

void decomp(int x) {
    for (int i = 1; i * i <= x; i++) {
        if (i * i == x) {
            cnt[i]++;
        }
        else if (x % i == 0) {
            cnt[i]++;
            cnt[x/i]++;
        }
    }
}

long long fastexp (long long x, long long e) {
    if (!e) return 1;
    long long ret = fastexp(x, e / 2);
    ret = ret * ret % MOD;
    if (e % 2) ret = ret * x % MOD;
    return ret;
}
int inv(int x) {
    return fastexp(x, MOD - 2);
}


int fak[NMAX * 2];
void init() {
    fak[0] = 1;
    for (int i = 1; i < NMAX * 2; i++) {
        fak[i] = fak[i-1] * i % MOD;
    }
}
int C(int n, int k) {
    if (n < k) return 0;
    return fak[n] * inv(fak[k]) % MOD * inv(fak[n-k]) % MOD;
}

void solve() {
    init();
    int n, k, m;
    cin >> n >> k >> m;

    vi vec(n);
    forn(i, n) cin >> vec[i];

    forn(i, n) {
        decomp(vec[i]);
    }    

    forn(i, NMAX) {
        val[i] = C(cnt[i], k);
    }

    for (int i = NMAX - 1; i > 0; i--) {
        for (int j = i * 2; j < NMAX; j += i) {
            val[i] -= val[j];
            val[i] = (val[i] + MOD) % MOD;
        }
        val[i] %= MOD;
    }

    cout << val[m] << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tc = 1;
    // cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}