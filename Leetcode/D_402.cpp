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
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        FT ft(sz(nums));
        vector<int> a(nums.begin(),nums.end());
        rep(i,0,sz(nums)) {
            if(i>0 && i+1<sz(nums) && nums[i]>nums[i-1] && nums[i]>nums[i+1]) {
                ft.update(i, 1ll);
            } 
        }
        vector<int> v;
        auto upd = [&](int idx) -> void {
            if(!(idx>0 && idx+1<sz(a))) return;
            int prv = ft.query(idx+1)-ft.query(idx);
            int now = 0;
            if(a[idx]>a[idx-1] && a[idx]>a[idx+1]) {
                now = 1;
            } else {
                now = 0;
            }
            if(now-prv!=0) {
                ft.update(idx, now-prv);
            }
        };
        rep(i,0,sz(queries)) {
            int qt = queries[i][0];
            if(qt==1) {
                int l=queries[i][1], r = queries[i][2];
                int ans = ft.query(r);
                if(l==r) {
                    ans = 0;
                } else {
                    ans -= ft.query(l+1);
                }
                v.push_back(ans);
            } else {
                int idx = queries[i][1], x = queries[i][2];
                a[idx] = x;
                upd(idx);
                upd(idx-1);
                upd(idx+1);
            }
        }
        return v;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    vector<int> a = {4,1,4,2,1,5};
    vector<vector<int>> qry = {{2,2,4},{1,0,2},{1,0,4}};
    auto ret = sol.countOfPeaks(a, qry);
    rep(i,0,sz(ret)) {
        cout <<ret[i] <<" \n"[i==sz(ret)-1];
    }
}