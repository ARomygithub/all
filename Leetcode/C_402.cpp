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
typedef pair<int,ll> pil;

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
    long long maximumTotalDamage(vector<int>& power) {
        map<int,ll> mp;
        rep(i,0,sz(power)) {
            mp[power[i]] += 1ll*power[i];
        }
        vector<pil> v;
        for(auto [k,val]: mp) {
            v.push_back({k,val});
        }
        sort(v.begin(),v.end());
        vector<ll> dp(sz(v),0ll);
        rep(i,0,sz(v)) {
            ll ls = i>0?dp[i-1]:0ll;
            ll temp = v[i].se;
            int j = i-1;
            while(j>=0 && v[i].fi-v[j].fi<=2) {
                j--;
            }
            temp += j>=0?dp[j]:0ll;
            dp[i] = max(ls, temp);
        }
        return dp[sz(v)-1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    vector<int> a = {7,1,6,6};
    cout <<sol.maximumTotalDamage(a);
}