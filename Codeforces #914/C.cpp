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

const int mxn=2e3;
int n,k,t;
ll a[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    if(k>=3) {
        cout <<"0\n";
        return;
    }
    ll ans=1e18;
    sort(a,a+n);
    min_self(ans,a[0]);
    rep(i,0,n-1) {
        min_self(ans,a[i+1]-a[i]);
    }
    if(k==2) {
        rep(i,0,n) {
            rep(j,i+1,n) {
                auto it = lower_bound(a,a+n,a[j]-a[i]);
                // cout <<(*it) <<"\n";
                if(it!=(a+n)) {
                    min_self(ans, (*it)-(a[j]-a[i]));
                } else {
                    // cout <<"cover1\n";
                }
                if(it!=a) {
                    it--;
                    min_self(ans, (a[j]-a[i])-(*it));
                } else {
                    // cout <<"cover2\n";
                }
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