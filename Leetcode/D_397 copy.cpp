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
    vector<int> findPermutation(vector<int>& nums) {
        int ct = 1e5;
        vector<int> ans;
        rep(q0,0,sz(nums)) {
            vector dp((1<<sz(nums)), vector<int>(sz(nums),1e9));
            vector p((1<<sz(nums)), vector<int>(sz(nums),-1));
            per(bit, (1<<sz(nums))-1, -1) {
                vector<int> v0,v1;
                rep(j,0,sz(nums)) {
                    if((bit>>j)&1) {
                        v1.push_back(j);
                    } else {
                        v0.push_back(j);
                    }
                }
                rep(ilast,0,sz(v1)) {
                    int last = v1[ilast];
                    if(last==q0 && bit!=(1<<q0)) continue;
                    rep(inxt, 0, sz(v0)) {
                        int nxt = v0[inxt];
                        bool comp = (bit^(1<<nxt))==((1<<sz(nums))-1);
                        if(comp) {
                            if(dp[bit][last] > abs(last-nums[nxt])+abs(nxt-nums[q0])) {
                                dp[bit][last] = abs(last-nums[nxt])+abs(nxt-nums[q0]);
                                p[bit][last] = nxt;
                            }
                        } else {
                            int bitn = bit ^ (1<<nxt);
                            int lastn = nxt;
                            int temp = abs(last-nums[nxt]) + dp[bitn][lastn];
                            if(dp[bit][last] > temp) {
                                dp[bit][last] = temp;
                                p[bit][last] = nxt;
                            }
                        }
                    }
                }
            }
            if(dp[1<<q0][q0] < ct) {
                ct = dp[1<<q0][q0];
                ans.clear();
                int bitu, lu;
                bitu = 1<<q0;
                lu = q0;
                // cout <<"ct " <<ct <<endl;
                ans.push_back(lu);
                while(bitu != (1<<sz(nums))-1) {
                    int cur = p[bitu][lu];
                    ans.push_back(cur);
                    // assert(bitu < (bitu ^ (1<<cur)));
                    bitu = bitu ^ (1<<cur);
                    lu = cur;
                }
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
    // int n = rng()%12 + 2;
    // vector<int> nums;
    // rep(i,0,n) {
    //     nums.push_back(i);
    // }
    // shuffle(nums.begin(), nums.end(), rng);
    // rep(i,0,sz(nums)) {
    //     cout <<nums[i] <<" \n"[i==sz(nums)-1];
    // }
    vector<int> nums = {1,3,5,10,6,7,12,4,8,11,13,2,9,0};
    auto ret = sol.findPermutation(nums);
    rep(i,0,sz(ret)) {
        cout <<ret[i] <<endl;
    }
}