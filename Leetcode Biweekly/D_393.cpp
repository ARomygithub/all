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
    int get_ans(int st, vector<int>& a, int mst, vector<int>& an, vector<vector<int>>& dp) {
        if(dp[st][mst]!=-2) return dp[st][mst];
        dp[st][mst] = -1;
        int ani = (1<<17)-1;
        if(mst==sz(an)-1) {
            rep(i,st,sz(a)) {
                ani = ani&a[i];
            }
            if(ani==an[mst]) {
                dp[st][mst] = a[sz(a)-1];
            }
            return dp[st][mst];
        }
        rep(i,st,sz(a)) {
            ani = ani&a[i];
            if((sz(an)-1-mst)+i>= sz(a)) break;
            if((ani&an[mst])==an[mst]) {
                if(ani==an[mst]) {
                    int temp = get_ans(i+1,a,mst+1,an,dp);
                    if(temp>0) {
                        if(dp[st][mst]==-1 || (dp[st][mst]>temp+a[i])) {
                            dp[st][mst] = temp+a[i];
                        }
                    }
                }
            } else {
                break;
            }
        }
        return dp[st][mst];
    }

    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        vector dp(sz(nums), vector<int>(sz(andValues),-2));
        int ans = get_ans(0,nums, 0, andValues, dp);
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    vector<int> nums = {1,2,3,4};
    vector<int> an = {2};
    cout <<sol.minimumValueSum(nums,an) <<endl;
}