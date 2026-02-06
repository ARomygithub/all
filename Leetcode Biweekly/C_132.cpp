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
    int maximumLength(vector<int>& nums, int k) {
        vector<map<int,int>> dp(k+1);
        rep(i,0,sz(nums)) {
            vector<map<int,int>> dp_new(k+1);
            max_self(dp_new[0][nums[i]], 1);
            rep(j,0,k+1) {
                for(auto [l,m]: dp[j]) {
                    max_self(dp_new[j][l], m);
                    if(nums[i]==l) {
                        max_self(dp_new[j][l], m+1);
                    } else if(j+1<=k) {
                        max_self(dp_new[j+1][nums[i]], m+1);
                    }
                }
            }
            int ls = 0;
            rep(j,0,k+1) {
                int ls_new = ls;
                vector<int> temp;
                for(auto [l,m]: dp[j]) {
                    if(m<=ls) {
                        temp.push_back(l);
                    }
                    max_self(ls_new, m);
                }
                for(auto id: temp) {
                    dp[j].erase(id);
                }
                ls = ls_new;
            }
            dp.swap(dp_new);
        }
        int ans = 1;
        rep(i,0,k+1) {
            for(auto [l,m]: dp[i]) {
                max_self(ans, m);
            }
        } 
        return ans;
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    // vector<int> nums({1,2,3,4,5,1});
    int n = 5e2;
    vector<int> nums(n);
    rep(i,0,n) {
        nums[i] = rng()%n;
    }
    cout <<sol.maximumLength(nums, 50);
}