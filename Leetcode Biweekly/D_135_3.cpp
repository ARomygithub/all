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
    long long maximumScore(vector<vector<int>>& grid) {
        int n = sz(grid), m = sz(grid[0]);
        vector sm(sz(grid[0]), vector<ll>(sz(grid)+1,0));
        rep(j,0,sz(grid[0])) {
            rep(i,1,sz(grid)+1) {
                sm[j][i] = sm[j][i-1] + grid[i-1][j];
            }
        }
        vector dp(n+1, vector<ll>(n+1,0));
        rep(j,1,m) {
            vector dp_new(n+1, vector<ll>(n+1,0));
            rep(i2,0,n+1) {
                vector<ll> pref(n+1, -1e15);
                rep(i3,0,n+1) {
                    if(i3>0) {
                        max_self(pref[i3], pref[i3-1]);
                    }
                    max_self(pref[i3], dp[i2][i3]-max(0ll, sm[j-1][i3]-sm[j-1][i2]));
                }
                vector<ll> suf(n+1, -1e15);
                per(i3,n,-1) {
                    if(i3<n) {
                        max_self(suf[i3], suf[i3+1]);
                    }
                    max_self(suf[i3], dp[i2][i3]);
                }
                rep(i1,0,n+1) {
                    if(j-2>=0) {
                        max_self(dp_new[i1][i2], pref[i1] + max(0ll, sm[j][i2]-sm[j][i1]) + max(0ll, sm[j-1][i1]-sm[j-1][i2]));
                        if(i1+1<=n) {
                            max_self(dp_new[i1][i2], max(0ll, sm[j][i2]-sm[j][i1]) + suf[i1+1]);
                        }
                    } else {
                        ll pr=0, nx=0;
                        nx += max(0ll, sm[j][i2]-sm[j][i1]);
                        nx += max(0ll, sm[j-1][i1]-sm[j-1][i2]);
                        max_self(dp_new[i1][i2], nx-pr);
                    }
                }
            }
            dp.swap(dp_new);
        }
        ll ret = 0;
        rep(i1,0,n+1) {
            rep(i2,0,n+1) {
                max_self(ret, dp[i1][i2]);
            }
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}