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
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        per(i,2,-1) {
            int x = nums2[0]-nums1[i];
            int ct = 2-i;
            map<int,int> mp1,mp2;
            rep(j,i+1,sz(nums1)) {
                mp1[nums1[j]+x]++;
            }
            rep(j,1,sz(nums2)) {
                mp2[nums2[j]]++;
            }
            int a=0,b=0;
            for(auto [k,v]: mp1) {
                if(mp2[k]< v) {
                    a += v-mp2[k];
                }
            }
            for(auto [k,v]: mp2) {
                if(mp1[k]< v) {
                    b += v-mp1[k];
                }
            }
            if(a==ct && b==0) {
                return x;
            }
        }
        return nums2[0]-nums1[0];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}