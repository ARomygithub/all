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

int n,k;
ll k2;
typedef unsigned long long ull;
const ll mod = (119 << 23) + 1, root = 62; // = 998244353
typedef vector<ll> vl;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(-1ULL / b) {}
	ull reduce(ull a) { // a % b + (0 or b)
		return a - (ull)((__uint128_t(m) * a) >> 64) * b;
	}
} fastMod(mod);

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=fastMod.reduce(ret*a);}
        a = fastMod.reduce(a*a);
        b >>=1;
    }
    return ret;
}
ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = fastMod.reduce(b*b), e /= 2)
		if (e & 1) ans = fastMod.reduce(ans*b);
	return ans;
}
ll modpow2[32];
// https://github.com/kth-competitive-programming/kactl/blob/main/content/numerical/NumberTheoreticTransform.h
void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, modpow(root,mod>>s)};
		rep(i,k,2*k) rt[i] = fastMod.reduce(rt[i / 2] * z[i & 1]);
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = fastMod.reduce(rt[j + k] * a[i + j + k]), &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B =32-__builtin_clz(s) , n = 1 << B;
	int inv = modpow(n,mod-2);
    // cout <<inv <<"\n";
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n) out[-i & (n - 1)] = fastMod.reduce(fastMod.reduce((ll)L[i] * R[i]) * inv);
	ntt(out);
	return {out.begin(), out.begin() + s};
}

vl mul(vl a, vl b) {
    vl ret = conv(a,b);
    int u=0;
    rep(i,k2,sz(ret)) {
        ret[u] = fastMod.reduce(ret[u]+ret[i]);
        u = (u+1==k2?0:u+1);
    }
    if(sz(ret)>k2) {
        ret.resize(k2);
    }
    return ret;
}

vl polFastExpo(vl a, int n) {
    vl ret(1,1);
    while(n) {
        if(n&1) ret = mul(ret,a);
        a = mul(a,a);
        n >>=1;
    }
    return ret;
}

void solve() {
    // ll u = 1;
    // int ui = 32-__builtin_clz(mod);
    // ui--;
    // while(ui>=0) {
    //     if((mod>>ui)&1) u = u*root%mod;
    //     modpow2[ui] = u;
    //     u = u*u%mod;
    //     ui--;
    // }
    cin >>k >>n;
    k2 = fastexpo(2ll,k);
    // invN = modpow(k2 << 1,mod-2);
    vl b(2,1);
    b = polFastExpo(b, n);
    rep(i,0,k2) {
        cout <<(i<sz(b)?b[i]%mod:0) <<" \n"[i==k2-1];
    }
    // cout <<invN <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}