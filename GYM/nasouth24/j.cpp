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

const int mxn=1e5;
ll n;

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
    ll mul = 1;
    while((n%4)==0) {
        mul *= 2;
        n /= 4;
    }
    if((n%8)==7) {
        cout <<"-1\n";
        return;
    }
    for(ll x = 0;x*x*3<=n;x++) {
        ll ni = n - x*x;
        auto fct = factor(ni);
        map<int,int> mp;
        for(auto u : fct) {
            mp[u]++;
        }
        bool ok = 1;
        for(auto [k,v]: mp) {
            if((k%4)==3 && (v%2)==1) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            for(ll y = 0;y*y*2<=ni;y++) {
                ll z = -1;
                ll l = 0, r = ceil(sqrt(ni));
                while(l<=r) {
                    ll mid = (l+r)/2;
                    ll cur = y*y+mid*mid;
                    if(cur==ni) {
                        z = mid;
                        break;
                    }
                    if(cur>ni) {
                        r = mid-1;
                    } else {
                        l = mid+1;
                    }
                }
                if(z!=-1) {
                    x *= mul;
                    y *= mul;
                    z *= mul;
                    cout <<x <<" " <<y <<" " <<z <<"\n";
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}