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
ll p[mxn],x;

void solve() {
    cin >>n >>p[0] >>x;
    ll s=0;
    rep(i,0,n) {
        ll d; cin >>d;
        if(i+1<n) {
            p[i+1] = p[i]+d;
        }
        s +=d;
    }
    ll ans=2e9;
    s *=-1;
    rep(i,0,n) {
        if(p[i]>=x) {
            ll temp = (p[i]-x)/s;
            min_self(ans, p[i]-temp*s);
        }
    }
    if(ans==2e9) {
        ans = -1;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}