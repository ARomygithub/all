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
typedef pair<int,pii> pipi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
const double eps = 1e-9;
int n,m;
vector<pipi> adj[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v,b,c; cin >>u >>v >>b >>c;
        u--,v--;
        adj[u].push_back({v,{b,c}});
    }
    double l=0, r = 1e4;
    double ans=0;
    while(r-l>eps) {
        double mid = (l+r)/2.0;
        vector<double> dp(n,-3e9);
        dp[0] = 0;
        rep(i,0,n-1) {
            for(auto [v,bc]: adj[i]) {
                auto [b,c] = bc;
                max_self(dp[v], dp[i]+1.0*b-mid*c);
            }
        }
        if(dp[n-1]>=0.0) {
            ans = mid;
            l = mid;
        } else {
            r = mid;
        }
    }
    cout <<fixed <<setprecision(10) <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}