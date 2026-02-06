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
    int maxSelectedElements(vector<int>& nums) {
        int mxn = 1e6;
        vector<int> dp(mxn+2,0);
        sort(nums.begin(),nums.end());
        rep(i,0,sz(nums)) {
            max_self(dp[nums[i]+1], 1 + dp[nums[i]]);
            max_self(dp[nums[i]], 1 + dp[nums[i]-1]);
        }                
        int ans = 0;
        rep(i,0,mxn+2) {
            max_self(ans, dp[i]);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> nums(2000,1);
    Solution sol;
    cout <<sol.maxOperations(nums) <<"\n";
}