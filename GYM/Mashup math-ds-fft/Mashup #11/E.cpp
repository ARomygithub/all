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

const int mxn=1e5,mxs=317;
int n;
int a[mxn];
vi mp(mxn + mxn*mxs,0);

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    int ans = 1;
    rep(d,-mxs,mxs+1) {
        int bwh = max(0, d*(n-1));
        rep(i,0,n) {
            ll cur = 1ll*a[i]-1ll*i*d;
            mp[cur+bwh]++;
            max_self(ans, mp[cur+bwh]);
        }
        rep(i,0,n) {
            ll cur = 1ll*a[i]-1ll*i*d;
            mp[cur+bwh] = 0;
        }
    }
    vector dp(mxs, vi(mxn*2+1, 0));
    rep(i,0,n) {
        int cur = i%mxs;
        rep(j,1,mxs) {
            if(i+j>=n) continue;
            int nx = (i+j)%mxs;
            if(((a[i+j]-a[i])%j) == 0) {
                int d = (a[i+j]-a[i])/j;
                max_self(dp[nx][d+mxn], dp[cur][d+mxn]+1);
                max_self(ans, dp[nx][d+mxn]+1);
            }
        }
        rep(j,1,mxs) {
            if(i-j<0) continue;
            if(((a[i]-a[i-j])%j)==0) {
                int d = (a[i]-a[i-j])/j;
                dp[cur][d+mxn] = 0;
            }
        }
    }
    cout <<n-ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}