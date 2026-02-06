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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=3e5;
const ll mod = 998244353;
const int mxa = 3e5;
ll fct[mxa+1], ifc[mxa+1], iv[mxa+1];
int n,m;
pii lr[mxn];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

void init_fac() {
    iv[1]=1;
    for(int i=2;i<=mxa;i++) {
        iv[i] = mod - mod/i*iv[mod%i]%mod;
    }
    fct[0]=1, ifc[0]=1;
    for(int i=1;i<=mxa;i++) {
        fct[i]=fct[i-1]*i%mod;
        ifc[i]=ifc[i-1]*iv[i]%mod;
    }
}

ll C(ll a, ll b) {
    if(a<b || a<0 || b<0) return 0;
    ll ret=fct[a];
    ret = ret*ifc[b] %mod;
    ret = ret*ifc[a-b] %mod;
    return ret;
}

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

void solve() {
    cin >>n >> m;
    vector<int> add(n+1,0), rem(n+1,0);
    rep(i,0,n) {
        cin >>lr[i].fi >> lr[i].se;
        add[lr[i].fi]++; rem[lr[i].se]++;
    }
    vector<pii> vm(m);
    rep(i,0,m) {
        cin >>vm[i].fi >>vm[i].se; 
        vm[i].fi--; vm[i].se--;
    }
    vector<int> v(n+1);
    int ct = 0;
    rep(i,1,n+1) {
        ct += add[i];
        v[i] = ct;
        ct -= rem[i];
    }
    vector<FT> vft(m*2+1, FT(n));
    rep(i,0,m*2+1) {
        rep(j,0,n) {
            vft[i].update(j, C(v[j+1]-i,j+1-i));
        }
    }
    ll ans = 0;
    rep(i,0,1<<m) {
        int l=1,r=n;
        int pop = 0;
        set<int> sm;
        rep(j,0,m) {
            if((i>>j)&1) {
                pop++;
                int le = vm[j].fi, ri = vm[j].se;
                max_self(l, lr[le].fi);
                max_self(l, lr[ri].fi);
                min_self(r, lr[le].se);
                min_self(r, lr[ri].se);
                sm.insert(le);
                sm.insert(ri);
            }
        }
        if(r>=l) {
            ll temp = vft[sz(sm)].query(r) - vft[sz(sm)].query(l-1);
            temp %=mod;
            ans = (ans + temp*((pop%2)?-1:1) + mod)%mod;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_fac();
    solve();
}