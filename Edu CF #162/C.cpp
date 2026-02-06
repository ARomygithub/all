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

const int mxn=3e5;
int n,q,t;
ll c[mxn];

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>c[i];
    }
    vector<ll> pref(n+1,0);
    rep(i,0,n) {
        pref[i+1] = pref[i];
        if(c[i]>1) {
            pref[i+1] += c[i];
        }
    }
    while(q--) {
        int l,r; cin >>l >>r;
        if(pref[r]-pref[l-1]>=r-l+1 && r-l+1!=1) {
            cout <<"YES\n";
        } else {
            cout <<"NO\n";
        }
    }
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