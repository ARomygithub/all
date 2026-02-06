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

const int mxn=2e5;
int n,t;
int a[mxn];
ll k;

void solve() {
    cin >>n >>k;
    int mn =1e9, mx=-1e9;
    rep(i,0,n) {
        cin >>a[i];
        min_self(mn, a[i]);
        max_self(mx, a[i]);
    }
    int u = (k%2)==1?mx:mn;
    rep(i,0,n) {
        a[i] = abs(u-a[i]);
    }
    rep(i,0,n) {
        cout <<a[i] <<" \n"[i==n-1];
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