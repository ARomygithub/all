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
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<sz(nums);) {
            int j = i;
            while(j+1<sz(nums) && nums[j+1]>nums[j]) {
                j++;
            }
            max_self(ans,j-i+1);
            i = j+1;
        }
        for(int i=0;i<sz(nums);) {
            int j = i;
            while(j+1<sz(nums) && nums[j+1]<nums[j]) {
                j++;
            }
            max_self(ans,j-i+1);
            i = j+1;
        }        
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}