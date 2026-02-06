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

const int mxn=1e5,mxk=10;
int n,k;
int a[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<ll> pref(n+1,0ll);
    rep(i,1,n+1) {
        pref[i] = pref[i-1]+a[i-1];
    }
    vector dp(k+1, vector<ll>(k+1,-1e18));
    rep(i,0,n) {
        vector dp_new(k+1, vector<ll>(k+1, -1e18));
        if(i==0) {
            dp_new[0][0] = a[i];
            if(k>=1) {
                dp_new[1][1] = 1ll*a[i]*a[i];
            }
            dp.swap(dp_new);
            continue;
        }
        rep(j,0,k+1) {
            rep(l,0,k+1) {
                if(dp[j][l]==(-1e18)) continue;
                if(j<k) {
                    int l2 = l+1;
                    ll temp = 1ll*a[i]*a[i];
                    if(l2>1) {
                        temp = (pref[i+1]-pref[i+1-l2])*(pref[i+1]-pref[i+1-l2]);
                        temp -= (pref[i]-pref[i-l])*(pref[i]-pref[i-l]);
                    }
                    max_self(dp_new[j+1][l2], dp[j][l] + temp);  
                }
                max_self(dp_new[j][0], dp[j][l] + a[i]);
            }
        }
        dp.swap(dp_new);
    }
    ll ans = -1e18;
    rep(j,0,k+1) {
        rep(l,0,k+1) {
            max_self(ans, dp[j][l]);
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