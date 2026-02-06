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
int n;
vi adj[mxn];
int dp[mxn][2];

void dfs(int u) {
    for(int v: adj[u]) {
        dfs(v);
        max_self(dp[u][0], dp[v][0]);
        dp[u][1] += dp[v][1];
    }
    dp[u][0]++;
    max_self(dp[u][1],dp[u][0]);
}

void solve() {
    cin >>n;
    rep(i,1,n) {
        int pi; cin >>pi;
        pi--;
        adj[pi].push_back(i);
    }
    dfs(0);
    cout <<dp[0][1] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}