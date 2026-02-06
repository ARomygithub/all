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

const int mxn=1e5;
int n,m;
pii wv[mxn];
multiset<int> s;

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        int w,v; cin >>w >>v;
        wv[i] = {v, w*-1};
    }
    sort(wv,wv+n,greater<pii>());
    rep(i,0,m) {
        int si; cin >>si;
        s.insert(si);
    }
    ll ans=0;
    rep(i,0,n) {
        int w = wv[i].se*-1;
        auto it = s.lower_bound(w);
        if(it!=s.end()) {
            ans +=1ll*wv[i].fi;
            s.erase(it);
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