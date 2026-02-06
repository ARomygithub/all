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

const int mxn=100;
ll k,x,a,t;

void solve() {
    cin >>k >>x >>a;
    vector<ll> v(x);
    v[0] = 1;
    ll s = 1;
    rep(i,1,x) {
        v[i] = (s)/(k-1) + 1;
        s += v[i];
        if(a-s<=0) {
            cout <<"NO\n";
            return;
        }
    }
    if(1ll*(a-s)*k>1ll*a) {
        cout <<"YES\n";
    } else {
        cout <<"NO\n";
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