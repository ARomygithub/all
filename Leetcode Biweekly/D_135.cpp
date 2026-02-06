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

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        vector<ll> dp(sz(grid[0]),0);
        vector sm(sz(grid[0]), vector<ll>(sz(grid),0));
        rep(j,0,sz(grid[0])) {
            sm[j][0] = grid[0][j];
            rep(i,1,sz(grid)) {
                sm[j][i] = sm[j][i-1] + grid[i][j];
            }
        }
        int n = sz(grid), m = sz(grid[0]);
        rep(j,1,sz(grid[0])) {
            max_self(dp[j], dp[j-1]);
            max_self(dp[j], sm[j][n-1] + (j-2>=0?sm[j-2][n-1]:0ll) + (j-3>=0?dp[j-3]:0ll));
            max_self(dp[j], sm[j-1][n-1] + (j-2>=0?dp[j-2]:0ll));
            rep(i,0,n) {
                ll temp = (j-2>=0?sm[j-2][i]:0ll) + (sm[j-1][n-1]-sm[j-1][i]);
                max_self(dp[j], temp + (j-3>=0?dp[j-3]:0ll));
            }
            if(j<2) continue;
            rep(i,0,n) {
                ll temp = sm[j][n-1] + (j-3>=0?sm[j-3][i]:0ll) + (sm[j-2][n-1]-sm[j-2][i]);
                max_self(dp[j], temp + (j-4>=0?dp[j-4]:0ll));
            }
            rep(i,0,n) {
                ll temp = sm[j][i] + (sm[j-1][n-1]-sm[j-1][i]) + (j-3>=0?sm[j-3][n-1]:0ll);
                max_self(dp[j], temp + (j-4>=0?dp[j-4]:0ll));
            }
        }
        return dp[n-1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}