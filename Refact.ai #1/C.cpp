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

const int mxn=3e5;
int n,t;
int a[mxn];

int calc(int x, int y) {
    int ret = x;
    if(x>y) {
        ret--;
    } else if(x<y) {
        ret++;
    }
    return ret;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vi dp(3,-mxn*2);
    dp[0] = 0;
    rep(i,0,n) {
        vi dp_new(3,-mxn*2);
        dp_new[0] = calc(dp[0],a[i]);
        dp_new[1] = max(dp[0],dp[1]);
        dp_new[2] = calc(max(dp[1],dp[2]),a[i]);
        dp.swap(dp_new);
    }
    int ans = max(dp[2],dp[1]);
    // max_self(ans, dp[2]);
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