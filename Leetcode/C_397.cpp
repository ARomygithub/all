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
    int maxScore(vector<vector<int>>& grid) {
        int ans = -1e5;
        vector dp(sz(grid), vector<int>(sz(grid[0])));
        per(i,sz(grid)-1,-1) {
            per(j,sz(grid[0])-1,-1) {
                dp[i][j] = 0;
                rep(i2,i+1,sz(grid)) {
                    max_self(dp[i][j], grid[i2][j]-grid[i][j]+dp[i2][j]);
                }
                rep(j2,j+1,sz(grid[0])) {
                    max_self(dp[i][j], grid[i][j2]-grid[i][j]+dp[i][j2]);
                }
                max_self(ans, dp[i][j]);
            }
        }
        if(ans<=0) {
            ans = -1e5;
            rep(i,0,sz(grid)) {
                multiset<int> ms;
                rep(j,0,sz(grid[0])) {
                    ms.insert(grid[i][j]);
                }
                for(auto it = ++ms.begin();it!=ms.end();it++) {
                    auto it2 = it;
                    it2--;
                    max_self(ans, (*it2) - (*it));
                }
            }
            rep(j,0,sz(grid[0])) {
                multiset<int> ms;
                rep(i,0,sz(grid)) {
                    ms.insert(grid[i][j]);
                }
                for(auto it = ++ms.begin();it!=ms.end();it++) {
                    auto it2 = it;
                    it2--;
                    max_self(ans, (*it2) - (*it));
                }                
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> grid =  {{4,3,2}, {3,2,1}};
    Solution sol;   
    cout <<sol.maxScore(grid) <<endl;
}