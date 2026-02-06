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
    int minimumSubstringsInPartition(string s) {
        vector<int> dp(sz(s), 1e9);
        vector ct(sz(s), vector<int>(26,0));
        rep(i,0,sz(s)) {
            if(i>0) {
                rep(j,0,26) {
                    ct[i][j] = ct[i-1][j];
                }
            }
            ct[i][s[i]-'a']++;
        }
        per(i,sz(s)-1,-1) {
            rep(j,i,sz(s)) {
                int mn = 1e9, mx=0;
                rep(k,0,26) {
                    int cti = ct[j][k] - (i>0?ct[i-1][k]:0);
                    if(cti >0) {
                        min_self(mn, cti);
                        max_self(mx, cti);
                    }
                }
                if(mn==mx) {
                    min_self(dp[i], 1+(j+1<sz(dp)?dp[j+1]:0));
                }
            }
        }
        return dp[0];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}