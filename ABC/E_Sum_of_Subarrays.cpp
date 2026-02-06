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

const int mxn=3e5;
int n,q,t;
ll a[mxn+1];

void solve() {
    cin >>n >>q;
    rep(i,1,n+1) {
        cin >>a[i];
    }
    vector<ll> pref(n+1,0);
    rep(i,1,n+1) {
        pref[i] = pref[i-1]+a[i];
    }
    vector<ll> p1(n+1,0), p2(n+1,0);
    rep(i,1,n+1) {
        p1[i] = p1[i-1] + pref[i];
        p2[i] = p2[i-1] + pref[i]*i;
    }
    while(q--) {
        int l,r; cin >>l >>r;
        ll ans = (p2[r]- (l-1>0?p2[l-2]:0ll))*2 - (p1[r] - (l-1>0?p1[l-2]:0ll))*(l+r-1);
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}