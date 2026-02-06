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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e3;
int n,l,t;
pll ba[mxn];

void solve() {
    cin >>n >>l;
    rep(i,0,n) {
        cin >>ba[i].se >>ba[i].fi;
    }
    sort(ba,ba+n);
    int ans = 0;
    rep(i,0,n) {
        multiset<int> ms;
        ll stemp = 0;
        rep(j,i,n) {
            ms.insert(ba[j].se);
            stemp += ba[j].se;
            ll bb = ba[j].fi-ba[i].fi;
            while(stemp+bb>l && sz(ms)) {
                auto it = (--ms.end());
                stemp -= (*it);
                ms.erase(it);
            }
            if(stemp+bb<=l) {
                max_self(ans, sz(ms));
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