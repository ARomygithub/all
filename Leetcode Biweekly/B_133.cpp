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
    int minOperations(vector<int>& nums) {
        int ct = 0;
        rep(i,0,sz(nums)-2) {
            if(nums[i]!=1) {
                ct++;
                rep(j,0,3) {
                    nums[i+j] = 1-nums[i+j];
                }
            }
        }
        if(nums[sz(nums)-1]==1 && nums[sz(nums)-2]==1) {
            return ct;
        } else {
            return -1;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}