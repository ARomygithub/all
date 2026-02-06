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
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e3;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    ll ans = 0;
    vector dp(n, vector<int>(n,0));
    vector dp2(n,vector<pii>(n,{1e9,1e9}));
    map<ll,vector<pii>> mp;
    rep(i,0,n) {
        ll tmp = 0;
        rep(j,i,n) {
            tmp += a[j];
            mp[tmp].push_back({i,j});
        }
    }
    for(auto& [val,v]: mp) {
        rep(i,0,sz(v)) {
            auto [l1,r1] = v[i];
            auto it = lower_bound(v.begin(),v.end(), pii{r1+1,-1});
            while(it!=v.end()) {
                auto [l2,r2] = *it;
                min_self(dp2[l1][r2], pii{r1,l2});
                it++;
            }
        }
    }
    rep(len,2,n+1) {
        rep(i,0,n-len+1) {
            int j = i+len-1;
            if(dp2[i][j].fi!=1e9) {
                auto [l,r] = dp2[i][j];
                int lenx = r-l-1;
                // cout <<l <<" " <<r <<endl;
                dp[i][j] = ((j-i+1)-lenx-2)+dp[l+1][r-1];
            } else {
                dp[i][j] = len-1;
            }
        }
    }
    rep(i,0,n) {
        rep(j,i+1,n) {
            ans += dp[i][j];
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}