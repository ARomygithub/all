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

using piii= pair<pii,int>;
const int mxn=1e2;
int n,m;
vector<pii> adj[mxn];
map<piii,bool> dp;

bool getDp(int k, int i, int j) {
    if(dp.count({{i,j},k})) return dp[{{i,j},k}];
    for(auto [iv, ic]: adj[i]) {
        if(ic>=k) {
            bool lwn = getDp(ic,j,iv);
            if(!lwn) {
                dp[{{i,j},k}] = 1;
                return 1;
            }
        }
    }
    dp[{{i,j},k}] = 0;
    return 0;
}

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v; char c; cin >>u >>v >>c; u--,v--;
        adj[u].push_back({v,c-'a'});
    }
    vector ans(n, vi(n,-1));
    rep(i,0,n) {
        rep(j,0,n) {
            ans[i][j] = getDp(0,i,j);
        }
    }
    rep(i,0,n) {
        rep(j,0,n) {
            cout <<(ans[i][j]?'A':'B');
        }
        cout <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}