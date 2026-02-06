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
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        vector<ll> d(sz(nums));
        rep(i,0,sz(nums)) {
            d[i] = target[i]-nums[i];
        }
        ll cur = 0;
        ll ret = 0;
        rep(i,0,sz(d)) {
            ll tmp = abs(d[i]);
            if(cur<0 && d[i]<0) {
                if(d[i]>=cur) {
                    min_self(tmp, 0ll);
                } else {
                    min_self(tmp, cur-d[i]);
                }
            } else if(cur>=0 && d[i]>=0) {
                if(d[i]<=cur) {
                    min_self(tmp, 0ll);
                } else {
                    min_self(tmp, d[i]-cur);
                }
            }
            ret += tmp;
            cur = d[i];
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}