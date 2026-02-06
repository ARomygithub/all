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

#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        ll ct = 1ll*sz(nums)*(sz(nums)+1)/2;
        ll med = (ct+1)/2;
        set<int> s;
        rep(i,0,sz(nums)) {
            s.insert(nums[i]);
        }
        map<int,int> mp;
        int id = 0;
        for(auto si : s) {
            mp[si] = id++;
        }
        int x = 20;
        int l=max((id/2)-x, 1),r=min((id/2)+x,id);
        int ans = -1;
        while(l<=r) {
            int mid = (l+r)/2;
            Tree<int> oset;
            vector<int> last(id,-1);
            // rep(i,0,id) {
            //     oset.insert({last[i],i});
            // }
            ll now = 0;
            rep(i,0,sz(nums)) {
                int cur = mp[nums[i]];
                if(last[cur]!=-1) {
                    oset.erase(last[cur]);
                }
                last[cur] = i;
                oset.insert(last[cur]);
                int ls = -1;
                if(sz(oset)-(mid+1)<0) {
                    ls = 0;
                } else {
                    ls = (*oset.find_by_order(sz(oset)-(mid+1))) + 1;
                }
                now += 1ll*(i-ls+1);
            }
            if(now>=med) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
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
    vector<int> nums = {3,4,3,4,5};
    // vector<int> nums = {4,3,5,4};
    // vector<int> nums;
    // int mxn = 1e5;
    // int szi = rng()%mxn + 1;
    // rep(i,0,mxn) {
    //     nums.push_back((rng()%mxn)+1);
    // }
    cout <<sol.medianOfUniquenessArray(nums) <<endl;
}