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
    long long countAlternatingSubarrays(vector<int>& nums) {
        vector<int> r(sz(nums));
        r[sz(nums)-1] = sz(nums)-1;
        per(i,sz(nums)-2,-1) {
            if(nums[i]==nums[i+1]) {
                r[i] = i;
            } else {
                r[i] = r[i+1];
            }
        }
        ll ans = 0;
        rep(i,0,sz(nums)) {
            ans +=1ll*(r[i]-i+1);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}