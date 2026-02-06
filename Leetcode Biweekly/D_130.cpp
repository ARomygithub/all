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
    ll get_ct(ll x) {
        // cout <<"ct" <<endl;
        ll ret = 0;
        per(i,49,-1) {
            if((x>>i)&1) {
                ret += 1;
                if(i>0) {
                    ret += (1ll<<(i-1))*i;
                }
                ret += x - (1ll<<i);
                ll x2 = x - (1ll<<i);
                if(x2>0) {
                    ret += get_ct(x2);
                }
                return ret;
            }
        }
        return ret;
    }

    void get_ct2(vector<ll>& ct, ll x) {
        // cout <<"ct2" <<endl;
        per(i,49,-1) {
            if((x>>i)&1) {
                ct[i]++;
                rep(j,0,i) {
                    ct[j] += (1ll<<(i-1));
                }
                ct[i] += x - (1ll<<i);
                ll x2 = x - (1ll<<i);
                if(x2>0) {
                    get_ct2(ct, x2);
                }
                return;
            }
        }
    }

    ll fastexpo(ll a, ll b, ll md) {
        ll ret = 1;
        while(b) {
            if(b&1) ret = ret*a%md;
            a = a*a%md;
            b >>=1;
        }
        return ret;
    }

    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
        const int mxb = 50;
        vector<int> ans(sz(queries));
        rep(i,0,sz(queries)) {
            vector<ll> ct(mxb,0),ctl(mxb,0),ctr(mxb,0);
            ll fr = queries[i][0], to = queries[i][1], mod = queries[i][2];
            ll l = 0, r = (1ll<<(mxb-1));
            ll le = -1;
            while(l<=r) {
                ll mid = (l+r)/2;
                ll szi = get_ct(mid);
                if(szi < fr+1) {
                    le = mid;
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
            ll ri = -1;
            l = 0, r = (1ll<<(mxb-1));
            while(l<=r) {
                ll mid = (l+r)/2;
                ll szi = get_ct(mid);
                if(szi >= to+1) {
                    ri = mid;
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            get_ct2(ctl, le);
            get_ct2(ctr, ri);
            ll fr2 = 0;
            rep(j,0,sz(ctl)) {
                fr2 += ctl[j];
            }
            for(int idx = 0;fr2<fr;fr2++) {
                while(!(((le+1)>>idx)&1)) {
                    idx++;
                }
                ct[idx]--;
                idx++;
            }
            ll to2 = 0;
            rep(j,0,sz(ctr)) {
                to2 += ctr[j];
            }
            to2--;
            for(int idx=mxb-1;to2>to;to2--) {
                while(!((ri>>idx)&1)) {
                    idx--;
                }
                ct[idx]--;
                idx--;
            }
            ans[i] = 1;
            rep(j,0,sz(ct)) {
                ct[j] += ctr[j]-ctl[j];
                ans[i] = ans[i]*fastexpo(2ll,ct[j]*j,mod)%mod;
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
    vector<vector<ll>> que = {{7,7,4}};
    // cout <<sol.get_ct(4) <<endl;
    // cout <<sol.get_ct(5) <<endl;
    // cout <<sol.get_ct(6) <<endl;
    auto ret = sol.findProductsOfElements(que);
    rep(i,0,sz(ret)) {
        cout <<"what" <<endl;
        cout <<ret[i] <<endl;
    }
}