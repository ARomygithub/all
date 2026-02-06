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
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(),coins.end());
        ll l = 1;
        ll r = 1ll*k*coins[0];
        ll ans = -1;
        while(l<=r) {
            ll mid = (l+r)/2;
            ll x = 0;
            rep(i,1,(1<<sz(coins))) {
                ll lcm = 1;
                bool lbh = 0;
                bool odd = 0;
                rep(j,0,sz(coins)) {
                    if((i>>j)&1) {
                        ll temp = lcm/__gcd(lcm,1ll*coins[j]);
                        if((mid/coins[j])<temp) {
                            lbh = 1;
                            break;
                        }
                        lcm = temp*coins[j];
                        odd = (!odd);
                    }
                }
                if(lbh) continue;
                if(odd) {
                    x += (mid/lcm);
                } else {
                    x -= (mid/lcm);
                }
            }
            if(x>=k) {
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

}