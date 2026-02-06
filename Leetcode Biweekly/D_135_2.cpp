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
        vector dp(sz(grid[0]), vector<ll>(2,0ll));
        vector sm(sz(grid[0]), vector<ll>(sz(grid),0));
        rep(j,0,sz(grid[0])) {
            sm[j][0] = grid[0][j];
            rep(i,1,sz(grid)) {
                sm[j][i] = sm[j][i-1] + grid[i][j];
            }
        }
        int n = sz(grid), m = sz(grid[0]);
        vector dps(n, vector(m, vector(m, vector<ll>(2,0ll))));
        rep(tp,0,2) {
            if(tp==0) {
                rep(dwn,0,n) {
                    rep(len,1,m+1) {
                        rep(l,0,m-len+1) {
                            int r = l+len-1;
                            if(len==1) {
                                dps[dwn][l][r][tp] = sm[l][dwn];
                                continue;
                            }
                            max_self(dps[dwn][l][r][tp], dps[dwn][l][r-1][tp]);
                            per(i,n-1,0) {
                                max_self(dps[dwn][l][r][tp], (sm[r][n-1]-sm[r][i-1]) + dps[i-1][l][r-1][tp]);
                            }
                            max_self(dps[dwn][l][r][tp], sm[r][n-1]);
                        }
                    }
                }
            } else {
                per(dwn,n-1,-1) {
                    rep(len,1,m+1) {
                        rep(l,0,m-len+1) {
                            int r = l+len-1;
                            if(len==1) {
                                dps[dwn][l][r][tp] = sm[l][dwn];
                                continue;
                            }
                            max_self(dps[dwn][l][r][tp], dps[dwn][l][r-1][tp]);
                            rep(i,0,n-1) {
                                max_self(dps[dwn][l][r][tp], sm[r][i]+dps[i+1][l][r-1][tp]);
                            }
                            max_self(dps[dwn][l][r][tp], sm[r][n-1]);
                        }
                    }                    
                }
            }
        }
        rep(j,1,m) {
            rep(tp,0,2) {
                int dwn = tp==0?n-1:0;
                per(l,j,-1) {
                    ll temp = dps[dwn][l][j][tp];
                    max_self(dp[j][tp], temp + (l-2>=0?dp[l-2][1-tp]:0ll));
                }
            }
        }
        return max(dp[m-1][0], dp[m-1][1]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}