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

const int mxn=2e5;
int n,t;
ll a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    ll mn=a[0];
    vector<pll> v;
    ll ans = 0;
    rep(i,0,n) {
        if(i>0 && a[i]<a[i-1]) {
            v.push_back({mn,a[i-1]});
            mn = a[i];
        }
        if(i==n-1) {
            v.push_back({mn,a[i]});
        }
    }
    rep(i,0,sz(v)) {
        if(i+1<sz(v)) {
            ans += v[i].se;
        }
        if(i>0) {
            ans -= v[i].fi;
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