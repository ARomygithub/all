#include <bits/stdc++.h>
using namespace std;

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

typedef long long ll;
typedef pair<long long, long long> pll;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef vector<int> vi;

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);  // (^ 10% faster if double)
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vi rev(n);
    rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
            // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
            auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
            C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}
vd conv(const vd& a, const vd& b) {
    if (a.empty() || b.empty()) return {};
    vd res(sz(a) + sz(b) - 1);
    int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    rep(i,0,sz(b)) in[i].imag(b[i]);
    fft(in);
    for (C& x : in) x *= x;
    rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
    return res;
}

typedef vector<ll> vl;
template<int M> vl convMod(const vl &a, const vl &b) {
    if (a.empty() || b.empty()) return {};
    vl res(sz(a) + sz(b) - 1);
    int B=32-__builtin_clz(sz(res)), n=1<<B, cut=int(sqrt(M));
    vector<C> L(n), R(n), outs(n), outl(n);
    rep(i,0,sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
    rep(i,0,sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
    fft(L), fft(R);
    rep(i,0,n) {
        int j = -i & (n - 1);
        outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
        outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
    }
    fft(outl), fft(outs);
    rep(i,0,sz(res)) {
        ll av = ll(real(outl[i])+.5), cv = ll(imag(outs[i])+.5);
        ll bv = ll(imag(outl[i])+.5) + ll(real(outs[i])+.5);
        res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
    }
    return res;
}

const int mxn=1e3;
const ll mod = 998244353;
int n,k;
ll a[mxn], c[mxn];

void solve() {
    cin >>n >>k;
    for(int i=0;i<n;i++) {
        cin >>a[i] >>c[i];
    }
    ll ans = 0;
    vector<vector<ll>> dp(2, vector<ll>(k,0));
    for(int i=0;i<k;i++) {
        ll temp = a[0]*i % k;
        ll ct = ((c[0]+1)/k) + (((c[0]+1)%k)>=i+1);
        dp[0][temp] +=ct;
    }
    // debug() <<imie(dp[0][0]);
    // ans = (ans+dp[0][0])%mod;
    for(int i=1;i<n;i++) {
        vector<ll> cti(k, 0);
        for(int j=0;j<k;j++) {
            ll temp = a[i]*j %k;
            ll ct = ((c[i]+1)/k) + (((c[i]+1)%k)>=j+1);
            cti[temp] +=ct;
        }
        vl res = convMod<mod>(dp[0], cti);
        // debug() <<imie(cti);
        for(int j=0;j<k;j++) {
            dp[1][j] = 0;
            int idx = j;
            while(idx < (int)res.size()) {
                dp[1][j] = (dp[1][j] + res[idx]);
                idx +=k;
            }
            // for(int l=0;l<k;l++) {
            //     // if(cti[(j-l+)])
            //     ll temp = (dp[0][l] * cti[(j-l+k)%k])%mod;
            //     dp[1][j] = (dp[1][j]+temp)%mod;
            // }
        }
        dp[0].swap(dp[1]);
        // ans = (ans + dp[0][0])%mod;
        // debug() <<imie(dp[0][0]);
    }
    ans = dp[0][0]%mod;


    // -1
    ans = (ans+mod-1)%mod;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}