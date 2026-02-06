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

const int mxn=1e3;
int n;
pll a[mxn*2];
pll x;

void solve() {
    cin >>n;
    rep(i,0,n*2) {
        cin >>a[i].fi;
    }
    cin >>x.fi;
    a[0].se = 0;
    ll diff = 1;
    if(x.fi==a[0].fi) {
        x.se = 0;
    }
    rep(i,1,n*2) {
        a[i].se = a[i-1].se + (a[i].fi-a[i-1].fi)*diff;
        if(x.fi<=a[i].fi && x.fi>a[i-1].fi) {
            x.se = a[i-1].se + (x.fi-a[i-1].fi)*diff;
        }
        diff *=-1;
    }
    ll ans = 0;
    rep(i,0,n*2) {
        if(a[i].fi<x.fi) {
            double diffy = 1.0*(a[i].se-x.se)/(x.fi-a[i].fi)*x.fi;
            ll y = (ll)(ceil(1.0*x.se+diffy));
            max_self(ans, y);
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