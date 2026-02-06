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
int n,t;
ll k, a[mxn];

void solve() {
    cin >>n >>k;
    ll mx = 0;
    ll s = 0;
    rep(i,0,n) {
        cin >>a[i];
        max_self(mx, a[i]);
        s += a[i];
    }
    ll ans = 1;
    rep(i,2,n+1) {
        ll sb = mx*i;
        if(sb>=s) {
            if(sb-s<=k) {
                ans = i;
            }
        } else {
            ll bth = s%(1ll*i);
            if(bth>0) {
                bth = i-bth;
            }
            if(bth<=k) {
                ans = i;
            }
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}