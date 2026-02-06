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

const int mxn=3e3;
int n;
int h[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>h[i];
    }
    vector dp(n, vi(n,1));
    int ans = 1;
    rep(i,0,n) {
        rep(j,1,n) {
            if(i>=j && h[i-j]==h[i]) {
                dp[i][j] = 1+dp[i-j][j];
            }
            max_self(ans, dp[i][j]);
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