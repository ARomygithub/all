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

const int mxn=1e5;
int n,m;

void solve() {
    cin >>n >>m;
    map<int,int> mp;
    rep(i,0,n) {
        int ai; cin >>ai;
        mp[ai]++;
    }
    vector<pii> v;
    for(auto [k,val]: mp) {
        v.push_back({k,val});
    }
    sort(v.begin(),v.end());
    vector dp(3, vector<int>(3,0));
    rep(i,0,sz(v)) {
        vector dp_new(3, vector<int>(3,0));
        rep(l3,0,3) {
            rep(l2,0,3) {
                int cur = v[i].se-l2-l3;
                if(cur<0) continue;
                rep(l1,0,3) {
                    if(l1>0 && !(cur>=l1 && i+2<sz(v) && v[i+1].fi==v[i].fi+1 && v[i+2].fi==v[i].fi+2 && v[i+1].se>=l1+l2 && v[i+2].se>=l1)) {
                        continue;
                    }
                    max_self(dp_new[l2][l1], dp[l3][l2] + l1 + (cur-l1)/3);
                }
            }
        }
        dp.swap(dp_new);
    }
    int ans = 0;
    rep(i,0,3) {
        rep(j,0,3) {
            max_self(ans, dp[i][j]);
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}