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
ll n,k,t;
ll a[mxn],x[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>x[i];
    }
    vector<ll> d(n,0);
    rep(i,0,n) {
        d[abs(x[i])-1] += a[i];
    }
    rep(i,1,n) {
        d[i] +=d[i-1];
    }
    rep(i,0,n) {
        if(d[i]> k*(i+1)) {
            cout <<"NO\n";
            return;
        }
    }
    cout <<"YES\n";
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