#include <bits/stdc++.h>
using namespace std;

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

const int mxn=1e5, mod=840;
int n,q,x,y;
int dp[840], p[mxn], t[mxn];

void solve() {
    cin >>n >>x >>y;
    for(int i=0;i<n-1;i++) {
        cin >>p[i] >>t[i];
    }
    ll b0 = 1ll*x+y;
    for(int i=0;i<n-1;i++) {
        b0 +=t[i];
    }
    for(int i=0;i<mod;i++) {
        int ti = (i+x)%mod;
        int j=0;
        // cout <<"tes\n";
        // cout <<flush;
        while(j<n-1) {
            // cout <<"a\n";
            // cout <<flush;
            int temp = ((ti%p[j])==0?0:p[j]-(ti%p[j]));
            dp[i] += temp;
            ti = (ti+temp)%mod;
            ti = (ti+t[j])%mod;
            j++;
        }
    }
    cin >>q;
    while(q--) {
        int qi; cin >>qi;
        ll ans = b0+dp[qi%mod];
        ans +=qi;
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}