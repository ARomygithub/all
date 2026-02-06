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

const int mxn=1e5;
int n,x,ka;
using ipii = pair<int,pii>;

void solve() {
    cin >>n >>x >>ka;
    vector<ipii> v;
    rep(i,0,n) {
        int p,u,c; cin >>p >>u >>c;
        v.push_back({c,{p,u}});
    }
    sort(all(v));
    vector dp(2, vector<ll>(x+1,0));
    for(int i=0;i<n;) {
        int j = i;
        while(j<n && v[j].fi==v[i].fi) {
            j++;
        }
        rep(k,i,j) {
            auto [p,u] = v[k].se;
            per(xi,x,p-1) {
                max_self(dp[1][xi], dp[0][xi-p]+u+ka);
                max_self(dp[1][xi], dp[1][xi-p]+u);
            }
        }
        rep(xi,0,x+1) {
            max_self(dp[0][xi], dp[1][xi]);
            dp[1][xi] = 0;
        }
        i = j;
    }
    ll ans = 0;
    rep(xi,0,x+1) {
        max_self(ans, dp[0][xi]);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}