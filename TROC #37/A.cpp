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

const int mxn=1e5;
int n;
pii a[4];

void solve() {
    rep(i,0,4) {
        cin >>a[i].fi >>a[i].se;
    }
    int ans = 0;
    auto op = [&](pii lr1, pii lr2) -> pii {
        pii ret = lr2;
        if(lr1.se <=ret.fi || lr1.fi>=ret.se) return ret;
        if(lr1.fi<=ret.fi && lr1.se>=ret.se) {
            return {0,0};
        }
        if(lr1.fi>ret.fi) {
            ans += lr1.fi-ret.fi;
            ret.fi = lr1.fi;
        }
        ret.fi = min(ret.se, lr1.se);
        return ret;
    };
    vector<pii> v{a[0],a[1],a[3]};
    sort(v.begin(),v.end());
    rep(i,0,3) {
        a[2] = op(v[i],a[2]);
    }
    ans += a[2].se-a[2].fi;
    if(ans) {
        cout <<"Guitar solo (" <<ans <<" sec.)\n";
    } else {
        cout <<"No guitar solo :(\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}