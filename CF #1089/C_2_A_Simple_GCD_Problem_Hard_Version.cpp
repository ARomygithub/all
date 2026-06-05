#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=5e4;
const int mxa = 1e6, mxc = 3e3;
int n,t;
int a[mxn], b[mxn];
vi vpr;
map<int,int> mpr;

const int LIM = 1e6;
vi eratosthenes() {
    const int S = (int)round(sqrt(LIM)), R = LIM / 2;
    vi pr = {2}, sieve(S+1); pr.reserve(int(LIM/log(LIM)*1.1));
    vector<pii> cp;
    for (int i = 3; i <= S; i += 2) if (!sieve[i]) {
        cp.push_back({i, i * i / 2});
        for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
    }
    for (int L = 1; L <= R; L += S) {
        array<bool, S> block{};
        for (auto &[p, idx] : cp)
            for (int i=idx; i < S+L; idx = (i+=p)) block[i-L] = 1;
        rep(i,0,min(S, R - L))
            if (!block[i]) pr.push_back((L + i) * 2 + 1);
    }
    return pr;
}

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1) ans = modmul(ans, b, mod);
    return ans;
}

bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n-1), d = n >> s;
    for (ull a : A) {   // ^ count trailing zeroes
        ull p = modpow(a%n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}

ull pollard(ull n) {
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    auto f = [&](ull x) { return modmul(x, x, n) + i; };
    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) x = ++i, y = f(x);
        if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}
vector<ull> factor(ull n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ull x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), all(r));
    return l;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    int ans = 0;
    vi r(n,1);
    rep(i,0,n) {
        int lc;
        if(i==0) {
            lc = __gcd(a[i],a[i+1]);
        } else if(i==n-1) {
            lc = __gcd(a[i-1],a[i]);
        } else {
            int dl = __gcd(a[i-1],a[i]);
            int dr = __gcd(a[i],a[i+1]);
            int d = __gcd(dl, dr);
            lc = dl*(dr/d);
        }
        if(a[i]==lc) {
            if(lc*2 <= b[i]) {
                r[i] = b[i]/lc;
            }
        } else {
            if(lc <= b[i]) {
                a[i] = lc;
                ans++;
            }
        }
    }
    vi dp(mxc+1, 0);
    rep(i,0,mxc) {
        if(vpr[i] > r[0]) break;
        dp[i+1] = 1;
    }
    rep(i,1,n) {
        auto fct = factor(a[i]/__gcd(a[i-1],a[i]));
        for(auto fcti: fct) {
            if(fcti < LIM) {
                int idx = mpr[fcti]+1;
                if(idx < sz(dp)) {
                    dp[idx] = 0;
                } 
            }
        }
        vi dp_new(mxc+1,0);
        int mx = max(r[i-1],r[i]);
        int ct = 1;
        rep(j,0,mxc) {
            if(vpr[j] > mx) break;
            ct++;
        }
        vi pf(ct,0), sf(ct,0);
        rep(j,0,ct) {
            max_self(pf[j], dp[j]);
            if(j) {
                max_self(pf[j], pf[j-1]);
            }
        }
        per(j,ct-1,-1) {
            max_self(sf[j], dp[j]);
            if(j+1<ct) {
                max_self(sf[j], sf[j+1]);
            }
        }
        dp_new[0] = pf[ct-1];
        rep(j,1,ct) {
            if(vpr[j-1] > r[i]) break;
            int cur = pf[j-1];
            if(j+1<ct) {
                max_self(cur, sf[j+1]);
            }
            dp_new[j] = cur+1;
        }
        fct = factor(a[i-1]/__gcd(a[i-1],a[i]));
        for(auto fcti: fct) {
            if(fcti < LIM) {
                int idx = mpr[fcti]+1;
                if(idx < sz(dp)) {
                    dp_new[idx] = 0;
                } 
            }
        }        
        dp.swap(dp_new);
    }
    int dpm = 0;
    rep(i,0,sz(dp)) {
        max_self(dpm, dp[i]);
    }
    ans += dpm;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    vpr = eratosthenes();
    rep(i,0,sz(vpr)) {
        mpr[vpr[i]] = i;
    }
    while(t--) {
        solve();
    }
}