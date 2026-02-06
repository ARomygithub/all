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

const int mxn=2e5;
const ll mod = 998244353;
ll n,m;
ll a[mxn];

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
    auto f = [n](ull x) { return modmul(x, x, n) + 1; };
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
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

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = ret*a%mod;
        a = a*a%mod;
        b >>=1;
    }
    return ret;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mxm = 1e16;

void solve() {
    n = (rng()%20) + 1;
    m = (rng()%mxm) + 1;
    cout <<n <<" " <<m <<endl;
    rep(i,0,n) {
        a[i] = (rng()%mxm)+1;
    }
    auto ret = factor(m);
    set<ll> pr;
    for(auto reti: ret) {
        pr.insert(reti);
    }
    vector<ll> vpr;
    for(auto pri: pr) {
        vpr.push_back(pri);
    }
    vector<ll> g(1<<sz(vpr), 0);
    rep(i,0,n) {
        if((m%(a[i]))==0) {
            int bit = 0;
            ll u = m/a[i]; 
            rep(j,0,sz(vpr)) {
                if((u%vpr[j])==0) {
                  bit += (1<<j);  
                }
            }
            g[bit]++;
        }
    }
    rep(i,0,sz(vpr)) {
        rep(S,0,1<<sz(vpr)) {
            if((S>>i)&1) {
                g[S^(1<<i)] += g[S];
            }
        }
    }
    ll vio = 0;
    rep(i,1,1<<sz(vpr)) {
        int ct = __builtin_popcount(i);
        if(ct%2) {
            vio = (vio + fastexpo(2ll,g[i])-1+mod) %mod;
        } else {
            vio = (vio - fastexpo(2ll,g[i])+1+mod) %mod;   
        }
    }
    ll ans = (fastexpo(2ll,g[0])-1+mod)%mod;
    // cout <<ans <<" " <<vio <<endl;
    ans = (ans-vio+mod)%mod;
    cout <<ans <<"\n" <<flush;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(true) {
        solve();
    }
}