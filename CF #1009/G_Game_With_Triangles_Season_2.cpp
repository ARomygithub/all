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

const int mxn=400;
int n,t;
ll a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector dp(n-1, vector<ll>(n-1));
    vector flag(n-1, vector<bool>(n-1,0));
    function<ll(int,int)> getdp;
    getdp = [&](int l, int r) -> ll {
        if(r-l+1<3) return 0;
        if(flag[l][r]) return dp[l][r];
        flag[l][r] = 1;
        ll cur = 0;
        rep(i,l,r) {
            max_self(cur, getdp(l,i)+getdp(i+1,r));
        }
        rep(i,l+1,r) {
            ll x = a[l]*a[r]*a[i];
            x += getdp(l+1,i-1);
            x += getdp(i+1,r-1);
            max_self(cur, x);
        }
        dp[l][r] = cur;
        return cur;
    };
    ll ans = 0;
    rep(i,0,n-1) {
        rep(j,i+1,n-1) {
            ll cur = a[n-1]*a[i]*a[j];
            if(i>=3) {
                cur += getdp(0,i-1);
            }
            if(j-i-1>=3) {
                cur += getdp(i+1,j-1);
            }
            if(n-1 - (j+1) >=3) {
                cur += getdp(j+1, n-2);
            }
            max_self(ans, cur);
        }
    }
    max_self(ans, getdp(0,n-2));
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