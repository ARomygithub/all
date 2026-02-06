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
ll n,s;
pll ab[mxn];

void solve() {
    cin >>n >>s;
    ll mx = s,mn=s;
    rep(i,0,n) {
        cin >>ab[i].fi >>ab[i].se;
        max_self(mx, ab[i].fi);
        max_self(mx, ab[i].se);
        min_self(mn, ab[i].fi);
        min_self(mn, ab[i].se);
    }
    ll ans = 1e18;
    {
        vector<pll> v;
        rep(i,0,n) {
            if(ab[i].se>s && ab[i].fi<s) {
                v.push_back({ab[i].se,ab[i].fi});
            }
        }
        sort(all(v));
        vector<ll> smn(sz(v)+1,s);
        per(i,sz(v)-1,-1) {
            min_self(smn[i], v[i].se);
            if(i+1<sz(v)) {
                min_self(smn[i], smn[i+1]);
            }
        }
        rep(i,-1,sz(v)) {
            ll x = i>=0?v[i].fi : s;
            ll y = smn[i+1];
            min_self(ans, (x-s)+x-mn + mx-mn + (mx-y) + s-y );
        }
    }
    {
        vector<pll> v;
        rep(i,0,n) {
            if(ab[i].se<s && ab[i].fi>s) {
                v.push_back({ab[i].se,ab[i].fi});
            }
        }
        sort(all(v));
        vector<ll> pmx(sz(v),s);
        rep(i,0,sz(v)) {
            max_self(pmx[i], v[i].se);
            if(i) {
                max_self(pmx[i], pmx[i-1]);
            }
        }
        rep(i,-1,sz(v)) {
            ll x = i>=0?
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}