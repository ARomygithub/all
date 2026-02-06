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
int n,q;
ll x[mxn],p[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>x[i];
    }
    rep(i,0,n) {
        cin >>p[i];
    }
    cin >>q;
    vector<ll> pref(n,0);
    rep(i,0,n) {
        pref[i] = (i>0?pref[i-1]:0ll) + p[i];
    }
    while(q--) {
        int l,r; cin >>l >>r;
        auto le = lower_bound(x,x+n,l)-x;
        auto ri = upper_bound(x,x+n,r)-x;
        ll sm = (ri>0?pref[ri-1]:0ll) - (le>0?pref[le-1]:0ll);
        cout <<sm <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}