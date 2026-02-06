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
ll n,a,b;

void solve() {
    cin >>n >>a >>b;
    // ll d = __gcd(a,b);
    // a /= d;
    // b /= d;
    vector<ll> rb(a,1e18),val(a,1e18);
    rb[0] = 0;
    ll tmp = 0;
    val[0] = tmp;
    int i;
    for(i=1;i<a;) {
        if(((b*i)%a) == 0) break;
        ll bwh = (b-tmp+a-1)/a;
        tmp += bwh*a;
        ll cur = max(tmp,rb[i-1]);
        while(i<a && tmp>=b) {
            if(((b*i)%a) == 0) break;
            rb[i] = cur;
            tmp -= b;
            val[i] = tmp;
            i++;
        }
    }
    ll ans = 0;
    rep(j,0,i) {
        ll atas = rb[j], cur = val[j];
        auto g = [&](ll xi) -> ll {
            return n-cur+1-xi*a;
        };
        if(atas<=n) {
            ll x = (atas-cur)/a;
            ans += (n-atas+1)*(x+1);
            if(n-cur+1 > (x+1)*a) {
                ll y = (n-cur)/a;
                ans += (y-x)*(g(x+1)+g(y))/2;
            }
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}