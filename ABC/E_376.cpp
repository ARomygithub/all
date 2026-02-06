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
int n,k,t;
int a[mxn],b[mxn];

void solve() {
    cin >>n >>k;
    vector<pll> v;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    rep(i,0,n) {
        v.push_back({a[i],-b[i]});
    }
    sort(all(v));
    ll ans = 1e18;
    ll sm = 0;
    multiset<ll> ms;
    rep(i,0,n) {
        auto [ai,bi] = v[i];
        bi *= -1;
        if(i>=k-1) {
            min_self(ans, ai*bi + ai*sm);
        }
        ms.insert(bi);
        sm += bi;
        if(sz(ms)>k-1) {
            auto it = --ms.end();
            sm -= (*it);
            ms.erase(it);
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