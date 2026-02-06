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
int n,q,t;
int a[mxn];

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>a[i];
    }
    int st = 0;
    vector<ll> pref(n+1,0);
    rep(i,1,n+1) {
        pref[i] = pref[i-1] + a[i-1];
    }
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int c; cin >>c;
            st = (st+c)%n;
        } else {
            int l,r; cin >>l >>r; l--,r--;
            l = (st+l)%n;
            r = (st+r)%n;
            ll ans = 0;
            if(l<=r) {
                ans = pref[r+1] - pref[l];
            } else {
                ans += pref[n] - pref[l];
                ans += pref[r+1];
            }
            cout <<ans <<"\n";
        }
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