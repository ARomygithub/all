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
    int minOperations(int k) {
        int ans = k-1;
        int l=0,r=k-1;
        while(l<=r) {
            int mid = (l+r)/2;
            // cout <<"Mid " <<mid <<endl;
            int u = mid+2;
            int bw = u/2;
            int at = u-bw;
            // cout <<bw <<" " <<at <<"\n";
            if(1ll*bw*at>=1ll*k) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    sol.minOperations(11);
}