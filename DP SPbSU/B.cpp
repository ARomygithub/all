#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

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

const int MAXN = 3e5;
vector<vector<int>> adj(MAXN, vector<int>());
vector<int> members(MAXN, 0);
vector<long long> sum(MAXN, 0);
vector<int> depth(MAXN, INT_MAX);
vector<bool> vis(MAXN, false);
vector<int> v(MAXN, 0);

bool dfs(int p, int d){
    if(vis[p]) return false;
    vis[p] = true;
    for(auto u: adj[p]){
        if(dfs(u, d+1)){
            sum[p] += sum[u];
            members[p] += members[u];
        }
    }
    members[p]++;
    depth[p] = d;
    sum[p] += v[p];
    return true;
}

int main()
{
    fastio;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    for(int i=1; i<n; i++){
        int tmp; cin >> tmp;
        adj[i].push_back(tmp-1);
        adj[tmp-1].push_back(i);
    }
    dfs(0, 0);
    long long res = LLONG_MIN;
    for(int i=0; i<n; i++){
        long long cur = 0;
        for(auto u: adj[i]){
            if(depth[u] > depth[i]){
                cur += sum[u]*members[u];
            }else{
                cur += (sum[0]-sum[i])*(members[0]-members[i]);
            }
        }
        res = max(res, cur);
    }
    cout << res << '\n';
    return 0;
}