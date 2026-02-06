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
    long long maximumTotalCost(vector<int>& nums) {
        vector<ll> dp(sz(nums),-1e18);
        rep(i,0,sz(nums)) {
            if(i==0) {
                dp[i] = nums[0];
            } else if(i==1) {
                dp[i] = max(dp[i-1]+nums[1], 1ll*nums[0]-nums[1]);
            } else {
                dp[i] = max(dp[i-1]+nums[i], dp[i-2]+nums[i-1]-nums[i]);
            }
        }
        return dp[sz(nums)-1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}