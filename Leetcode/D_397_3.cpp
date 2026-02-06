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
        vector dp((1<<sz(nums)), vector(sz(nums), vector<int>(sz(nums),1e9)));
        vector p((1<<sz(nums)), vector(sz(nums), vector<int>(sz(nums), -1)));
        rep(nbit, 1, (1<<sz(nums))) {
            int bit = (1<<sz(nums))-nbit;
            rep(last,0,sz(nums)) {
                if(!((bit>>last)&1)) continue;
                rep(q0,0, sz(nums)) {
                    if(!((bit>>q0)&1)) continue;
                    if(last==q0 && bit!=(1<<q0)) continue;
                    rep(nxt, 0, sz(nums)) {
                        if((bit>>nxt)&1) continue;
                        bool comp = (bit^(1<<nxt))==((1<<sz(nums))-1);
                        if(comp) {
                            if(dp[nbit][last][q0] > abs(last-nums[nxt])+abs(nxt-nums[q0])) {
                                dp[nbit][last][q0] = abs(last-nums[nxt])+abs(nxt-nums[q0]);
                                p[nbit][last][q0] = nxt;
                            }
                        } else {
                            int bitn = bit ^ (1<<nxt);
                            int lastn = nxt;
                            int nbitn = (1<<sz(nums))-bitn;
                            int temp = abs(last-nums[nxt]) + dp[nbitn][lastn][q0];
                            if(dp[nbit][last][q0] > temp) {
                                dp[nbit][last][q0] = temp;
                                p[nbit][last][q0] = nxt;
                            }
                        }
                    }
                }
            }
        }
        int ct = 1e5;
        vector<int> ans;
        int nbitu, lu, q0u;
        rep(i,0,sz(nums)) {
            int nbitui = (1<<sz(nums)) - (1<<i);
            if(ct > dp[nbitui][i][i]) {
                ct = dp[nbitui][i][i];
                nbitu = nbitui;
                lu = i;
                q0u = i;
            }
        }
        ans.push_back(lu);
        while(nbitu != 1) {
            int cur = p[nbitu][lu][q0u];
            ans.push_back(cur);
            nbitu = nbitu - (1<<cur);
            lu = cur;
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
    // vector<int> nums = {11,5,6,2,9,0,12,13,4,8,1,3,7,10};
    auto ret = sol.findPermutation(nums);
    rep(i,0,sz(ret)) {
        cout <<ret[i] <<endl;
    }
}