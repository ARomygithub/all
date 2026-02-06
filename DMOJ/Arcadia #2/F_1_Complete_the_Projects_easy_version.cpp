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

const int mxn=100;
int n,r,t;

void solve() {
    cin >>n >>r;
    vector<pii> vp,vn;
    rep(i,0,n) {
        int a,b; cin >>a >>b;
        if(b>=0) {
            vp.push_back({a,b});
        } else {
            vn.push_back({a+b,b*-1});
        }
    }
    sort(all(vp));
    rep(i,0,sz(vp)) {
        if(r>=vp[i].fi) {
            r += vp[i].se;
        } else {
            cout <<"NO\n";
            return;
        }
    }
    sort(all(vn), greater<pii>());
    rep(i,0,sz(vn)) {
        r -= vn[i].se;
        if(r<vn[i].fi) {
            cout <<"NO\n";
            return;
        }
    }
    if(r<0) {
        cout <<"NO\n";
    } else {
        cout <<"YES\n";
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