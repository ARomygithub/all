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

const int mxn=2e3;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    vector<ll> pref(n+1);
    rep(i,0,n) {
        cin >>a[i];
        pref[i+1] = pref[i]+a[i];
    }
    ll ans = 0;
    vector dp(n+1, vector<int>(n+1,0));
    map<ll,int> mp;
    per(i,n-1,-1) {
        rep(j,i,n+1) {
            if(mp.count(pref[i]+pref[j])) {
                dp[i][j] = max(((j-i)-2-mp[pref[i]+pref[j]]),0);
            } else {
                dp[i][j] = max(j-i-1,0);
            }
            int lenx = (j-i)-dp[i][j];
            mp[pref[i]+pref[j]] = lenx;
            // ans += dp[i][j];
        }
    }
    rep(i,0,n) {
        rep(j,i+1,n+1) {
            ans += dp[i][j];
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