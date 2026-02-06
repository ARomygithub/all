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
    vector<ll> mul(vector<ll>& pol1, vector<ll>& pol2, int bts) {
        int szi = min(sz(pol1)+sz(pol2)-1, bts+1);
        const ll mod = 1e9+7;
        vector<ll> res(szi,0ll);
        rep(i,0,sz(pol1)) {
            if(i>=szi) continue;
            rep(j,0,min(sz(pol2), szi-i)) {
                res[i+j] = (res[i+j] + pol1[i]*pol2[j]%mod)%mod;
            }
        }
        return res;
    } 

    ll getCt(int l, int r, ll sum) {
        vector<ll> res(l+1,1ll);
        rep(i,l+1,r+1) {
            vector<ll> pol2(i+1,1ll);
            res = mul(res, pol2, sum);
        }
        if(sum<sz(res)) {
            return res[sum];
        } else {
            return 0ll;
        }
    }

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const ll mod = 1e9+7;
        vector<pii> req;
        rep(i,0,sz(requirements)) {
            req.push_back({requirements[i][0],requirements[i][1]});
        }
        sort(req.begin(),req.end());
        ll ans = 1;
        ll cur = 0;
        int ls = 0;
        rep(i,0,sz(req)) {
            if(i==0 && req[i].fi==0) {
                if(req[i].se!=0) {
                    return 0;
                }
                continue;
            }
            ll now = req[i].se - cur;
            if(now<0ll) {
                return 0;
            }
            ans = ans*getCt(ls+1,req[i].fi, now)%mod;
            ls = req[i].fi;
            cur = req[i].se;
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    vector<vector<int>> req = {{0,0},{1,0}};
    cout <<sol.numberOfPermutations(2, req);
}