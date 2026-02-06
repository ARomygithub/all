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
pii a[mxn];

void solve() {
    cin >>n;
    int ans = 0;
    rep(i,0,n) {
        cin >>a[i].fi >>a[i].se;
        max_self(ans, a[i].se-a[i].fi+1);
    }
    sort(a,a+n);
    int lmax = a[n-1].fi;
    vector<int> pref(n),suf(n);
    pref[0] = a[0].se;
    rep(i,1,n) {
        pref[i] = min(pref[i-1],a[i].se);
    }
    suf[n-1] = a[n-1].se;
    per(i,n-2,-1) {
        suf[i] = min(suf[i+1],a[i].se);
    }
    rep(i,0,n-1) {
        int ri = a[i].se;
        int rj = suf[i+1];
        max_self(ans, max(ri,rj)+min(min(ri,pref[i]),rj)+2-a[i].fi-lmax);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}