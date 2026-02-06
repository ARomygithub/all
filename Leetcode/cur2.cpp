#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
    int maxOperations(vector<int>& nums) {
        vector<int> skor(3);
        skor[0] = nums[0]+nums[1];
        skor[1] = nums[sz(nums)-2]+nums[sz(nums)-1];
        skor[2] = nums[0]+nums[sz(nums)-1];
        int n = sz(nums);
        vector dp(n-1, vector<vector<bool>>());
        rep(i,0,n-1) {
            int len = n-i;
            dp[i].resize(n-len+1, vector<bool>(3,0));
        }
        int ans = 0;
        rep(i,0,3) {
           dp[0][0][i] = 1;
        }
        rep(leni,0,n-1) {
            int len = n-leni;
            rep(i,0,n-len+1) {
                int j = i+len-1;
                rep(k,0,3) {
                    if(dp[leni][i][k]) {
                        if(nums[i]+nums[i+1]==skor[k]) {
                            max_self(ans, n-(len-2));
                            if(leni+2<n-1) {
                                dp[leni+2][i+2][k] = 1;
                            }
                        }
                        if(nums[j-1]+nums[j]==skor[k]) {
                            max_self(ans, n-(len-2));
                            if(leni+2<n-1) {
                                dp[leni+2][i][k] = 1;
                            }
                        }
                        if(nums[i]+nums[j]==skor[k]) {
                            max_self(ans, n-(len-2));
                            if(leni+2<n-1) {
                                dp[leni+2][i+1][k] = 1;
                            }
                        }
                    }
                }
            }
        }
        return ans/2;
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