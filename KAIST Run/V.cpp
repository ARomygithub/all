#include <bits/stdc++.h>
using namespace std;

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef pair<pii,ll> piil;
typedef pair<ll,pii> plii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=25e4;
int n,m,k;
double ans[mxn];
ll dp[mxn];
vector<int> adj[mxn];
vector<piil> edge;
int pe[mxn],pv[mxn];

void solve() {
    cin >>n >>m;
    memset(pe,-1,4*m);
    for(int i=0;i<m;i++) {
        int u,v; ll w; cin >>u >>v >>w; u--,v--;
        edge.push_back({{u,v},w});
        adj[u].push_back(sz(edge)-1);
        adj[v].push_back(sz(edge)-1);
    }
    cin >>k;
    vector<int> vk(k);
    for(int i=0;i<k;i++) {
        cin >>vk[i]; vk[i]--;
    }
    priority_queue<plii,vector<plii>,greater<plii>> pq;
    fill(dp,dp+n,1e18);
    fill(pv,pv+n,1e9);
    for(int i=0;i<k;i++) {
        dp[vk[i]] = 0;
        pv[vk[i]] = vk[i];
        pq.push({0ll,{vk[i],vk[i]}});
    }
    while(sz(pq)) {
        auto [w,uku] = pq.top(); pq.pop();
        auto [uk,u] = uku;
        if(w>dp[u] || uk>pv[u]) continue;
        for(auto ei : adj[u]) {
            piil edgei = edge[ei];
            int v = edgei.fi.fi+edgei.fi.se-u;
            ll wi = edgei.se;
            if(pe[ei]==-1) {
                ans[uk] +=wi;
                pe[ei] = uk;
                if(dp[v]>dp[u]+wi || (dp[v]==dp[u]+wi && pv[v]>uk)) {
                    dp[v] = dp[u]+wi;
                    pv[v] = uk;
                    pq.push({dp[v],{uk,v}});
                }
            } else {
                int vki = pe[ei];
                pe[ei] = 1e9;
                double x = (dp[v]-dp[u]+wi)*1.0/2;
                ans[uk] +=x;
                ans[vki] -=x;
            }
        }
    }
    for(int i=0;i<k;i++) {
        cout <<fixed <<setprecision(1) <<ans[vk[i]] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}