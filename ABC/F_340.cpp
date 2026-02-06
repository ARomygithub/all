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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
const ll ml=-1e18,mr=1e18;
ll xi,yi;

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

void solve() {
    cin >>xi >>yi;
    ll d= __gcd(xi,yi);
    d = abs(d);
    // cout <<d <<"\n";
    if((2ll)%d) {
        cout <<"-1\n";
    } else {
        ll ani,bi;
        euclid(xi,yi,bi,ani);
        bi *=2/d;
        ani *=2/d;
        ll p = yi/d, q=xi/d;
        if(ani<ml || ani >mr) {
            cout <<"-1\n";
        }
        if(bi<ml || bi>mr) {
            cout <<"-1\n";
        }
        cout <<ani*(-1ll) <<" " <<bi <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}