#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=300,mxa=180000;
const ll mod = 998244353;
int n;
int a[mxn];

void solve() {
    cin >>n;
    int s=0;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        s +=a[i];
    }
    vector<ll> dp(s*2+1,0);
    dp[s+a[1]] = 1;
    for(int i=2;i<n-1;i++) {
        vector<ll> new_dp(s*2+1,0);
        for(int j=0;j<=s*2;j++) {
            // assert(a[i]-(j-s)+s<=2*s && a[i]-(j-s)+s>=0);
            // assert(a[i]+(j-s)+s<=2*s && a[i]+(j-s)+s>=0);
            if(a[i]-(j-s)<s*-1 || a[i]-(j-s)>s) continue;
            if(a[i]+(j-s)<s*-1 || a[i]+(j-s)>s) continue;
            if(j-s==0) {
                new_dp[a[i]-(j-s)+s] =(new_dp[a[i]-(j-s)+s]+dp[j])%mod;
            } else {
                new_dp[a[i]-(j-s)+s] =(new_dp[a[i]-(j-s)+s]+dp[j])%mod;
                new_dp[a[i]+(j-s)+s] =(new_dp[a[i]+(j-s)+s]+dp[j])%mod;
            }
        }
        dp.swap(new_dp);
    }
    ll ans=0;
    for(int i=0;i<=s*2;i++) {
        if(i-s==0) {
            ans = (ans+dp[i])%mod;
        } else {
            ans = (ans+dp[i]*2)%mod;
        }
    }
    cout <<ans <<"\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}