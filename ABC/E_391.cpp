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

const int mxn=1e5;
int n;
string s;

void solve() {
    cin >>n;
    cin >>s;
    vector dp(n+1, vi());
    vector val(n+1, vector<bool>());
    int n3 = 1;
    rep(i,0,n) {
        n3 *= 3;
    }
    int un3 = n3;
    rep(i,0,n+1) {
        dp[i].resize(un3);
        val[i].resize(un3);
        un3 /= 3;
    }
    rep(i,0,n3) {
        val[0][i] = (s[i]=='1');
        dp[0][i] = 1;
    }
    rep(i,1,n+1) {
        rep(j,0,sz(dp[i])) {
            int j3 = j*3;
            int ct1 = (val[i-1][j3]) + (val[i-1][j3+1]) + (val[i-1][j3+2]);
            int ctv = 0;
            if(ct1>1) {
                val[i][j] = 1;
                ctv = ct1;
            } else {
                val[i][j] = 0;
                ctv = 3-ct1;
            }
            if(ctv==3) {
                int cur = dp[i-1][j3] + dp[i-1][j3+1] + dp[i-1][j3+2] - max(max(dp[i-1][j3], dp[i-1][j3+1]), dp[i-1][j3+2]);
                dp[i][j] = cur;
            } else {
                int mn = 2e9;
                rep(j3i,j3,j3+3) {
                    if(val[i-1][j3i] == val[i][j]) {
                        min_self(mn, dp[i-1][j3i]);
                    }
                }
                dp[i][j] = mn;
            }
        }
    }
    cout <<dp[n][0] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}