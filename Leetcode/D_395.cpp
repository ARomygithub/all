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

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) { // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    ll query(int pos) { // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
    int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
        // Returns n if no sum is >= sum, or -1 if empty sum is.
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
                pos += pw, sum -= s[pos-1];
        }
        return pos;
    }
};

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
        int l=1,r=id;
        int ans = -1;
        while(l<=r) {
            int mid = (l+r)/2;
            FT ft(sz(nums)+1);
            vector<int> last(id,-1);
            rep(i,0,id) {
                ft.update(0,1);
            }
            ll now = 0;
            rep(i,0,sz(nums)) {
                int cur = mp[nums[i]];
                ft.update(last[cur]+1, -1);
                last[cur] = i;
                ft.update(last[cur]+1, 1);
                int ls = -1;
                ls = ft.lower_bound(id-mid);
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
    // vector<int> nums = {3,4,3,4,5};
    // vector<int> nums = {4,3,5,4};
    vector<int> nums;
    int mxn = 1e5;
    int szi = rng()%mxn + 1;
    rep(i,0,mxn) {
        nums.push_back((rng()%mxn)+1);
    }
    cout <<sol.medianOfUniquenessArray(nums) <<endl;
}