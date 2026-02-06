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

const int mxn=60;
int n;
ll a[mxn],x;

void solve() {
    cin >>n >>x;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<ll> dp(2,2e18);
    dp[0] = 0;
    vector<ll> szi(n,2e18);
    rep(i,0,n-1) {
        szi[i] = a[i+1]/a[i];
    }
    assert((x%a[0])==0ll);
    vector<ll> bit(n,0);
    rep(i,0,n) {
        ll cur = x;
        if(i+1<n) {
            cur %= a[i+1];
        }
        bit[i] = cur/a[i];
        x -= cur;
    }
    rep(i,0,n) {
        vector<ll> dp_new(2,2e18);
        if(dp[0]!=2e18) {
            ll cur = bit[i];
            if(cur==0ll) {
                min_self(dp_new[0], dp[0]);
            } else {
                min_self(dp_new[0], dp[0] + cur);
                if(i+1<n) {
                    min_self(dp_new[1], dp[0] + szi[i]-cur);
                }
            }
        }
        if(dp[1]!=2e18) {
            ll cur = bit[i]+1;
            if(i+1<n) {
                if(cur==szi[i]) {
                    min_self(dp_new[1], dp[1]);
                } else {
                    min_self(dp_new[0], dp[1] + cur);
                    min_self(dp_new[1], dp[1] + szi[i]-cur);
                }
            } else {
                min_self(dp_new[0], dp[1]+cur);
            }
        }
        dp.swap(dp_new);
    }
    cout <<dp[0] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}