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
ll a,b,c,d;

void solve() {
    cin >>a >>b >>c >>d;
    ll ans = 0;
    rep(i,1,999) {
        rep(j,1,1000-i) {
            if(__gcd(i,j)!=1) continue;
            ll l = (a+i-1)/i;
            max_self(l, (c+j-1)/j);
            ll r = b/i;
            min_self(r, d/j);
            if(r>=l) {
                ans += r-l+1;
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