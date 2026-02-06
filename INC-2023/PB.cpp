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
int n;
ll t[mxn],ct[mxn],a[mxn],b[mxn];

void solve() {
    cin >>n;
    rep(i,0,n-1) {
        cin >>t[i];
    }
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    per(i,n-2,-1) {
        ct[i] = max(b[i+1]-a[i+1],0ll);
        a[i] -=ct[i];
    }
    if(b[0]>a[0]) {
        cout <<"-1\n";
    } else {
        ll ans=0;
        rep(i,0,n-1) {
            ans +=t[i]*ct[i];
        }
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}