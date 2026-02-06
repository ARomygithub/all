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
ll n,m,k;

void solve() {
    cin >>n >>m >>k;
    ll d = __gcd(n,m);
    n /=d; m/=d;
    ll l=1,r=4e18;
    ll ans = -1;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll now = mid - min(mid%n,mid%m);
        ll ct = (now/n) + (now/m) - (now/(n*m))*2;
        if(ct>k) {
            r = mid-1;
        } else if(ct<k) {
            l = mid+1;
        } else {
            if(now%(n*m)) {
                ans = now;
                break;
            } else {
                r = mid-1;
            }
        }
    }
    cout <<d*ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}