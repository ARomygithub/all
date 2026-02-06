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

const int mxn=1e5;
int n,t;

void solve() {
    cin >>n;
    ll ans = 0, ans2 = 0;
    for(int la=1;la<=n;la++) {
        int nx = n/(n/la);
        ans += 1ll*(n/la)*(nx-la+1);
        la = nx;
    }
    // rep(i,1,n+1) {
    //     ans += n/i;
    // }
    ans -= n;
    n--;
    for(int la=1;la<=n;la++) {
        int nx = n/(n/la);
        ans2 += 1ll*(n/la)*(nx-la+1);
        la = nx;        
    }
    cout <<ans <<" " <<ans2 <<"\n";
    // assert(ans,ans2);
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