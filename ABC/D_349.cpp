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
ll l,r;

ll getLarge(ll x) {
    ll ret = 1;
    while(ret*2-1 < x) {
        ret *=2ll;
    }
    return ret;
}

void solve() {
    cin >>l >>r;
    vector<pll> ans;
    ll lu = l;
    while(lu!=r) {
        ll temp = (lu!=0ll?(1ll<<(__builtin_ctzll(lu))):(1ll<<60));
        if(temp>r-lu) {
            temp = getLarge(r-lu);
        }
        ans.push_back({lu,lu+temp});
        lu +=temp;
    }
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i].fi <<" " <<ans[i].se <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}