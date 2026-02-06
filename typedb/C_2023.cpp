#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
#define pll pair<ll,ll>

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,t,s;
int a[mxn];

int res_mn(int x) {
    if(x<=s) return 0;
    return min(s,x-s);
}

int res_mx(int x) {
    if(x<=s) return x;
    return max(s,x-s);
}

void solve() {
    cin >>n >>s;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    ll ans=1e18;
    pll dp = {1ll*a[0]*res_mx(a[1]),1ll*a[0]*res_mn(a[1])};
        // cout <<dp.fi <<" " <<dp.se <<"\n";
    for(int i=2;i<=n-2;i++) {
        pll new_dp;
        new_dp.fi = min(1ll*res_mx(a[i])*res_mn(a[i-1])+dp.fi,1ll*res_mx(a[i])*res_mx(a[i-1])+dp.se);
        new_dp.se = min(1ll*res_mn(a[i])*res_mn(a[i-1])+dp.fi,1ll*res_mn(a[i])*res_mx(a[i-1])+dp.se);
        swap(dp,new_dp);
        // cout <<1ll*res_mx(a[i])*res_mx(a[i-1]+dp.se) <<"\n";
        // cout <<dp.fi <<" " <<dp.se <<"\n";
    }
    ans = min(1ll*a[n-1]*res_mn(a[n-2])+dp.fi,1ll*a[n-1]*res_mx(a[n-2])+dp.se);
    cout << ans <<"\n";
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