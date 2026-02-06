#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define fi first
#define se second

const int mxn = 1e3;
int n,m,k,mc;
vector<pii> adj[mxn];
int t[mxn];
using pli = pair<ll,int>;
using plii = pair<pli,int>;

void solve() {
    cin >>n >>m >>k >>mc;
    rep(i,0,m) {
        int u,v,c; cin >>u >>v >>c; u--,v--;
        int p = abs(u-v);
        if(c<5) {
            p += c*2;
        } else if(c<10) {
            p += c*3;
        } else {
            p += c*5;
        }
        adj[u].push_back({p,v});
        adj[v].push_back({p,u});
    }
    rep(i,0,n-1) {
        cin >>t[i];
    }
    vector<vector<int>> d;
    rep(i,0,n) {
        vi di(n,1e9);
        di[i] = 0; 
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,i});
        while(sz(pq)) {
            auto [dij, j] = pq.top(); pq.pop();
            if(di[j]<dij) continue;
            for(auto [p,v]: adj[j]) {
                if(di[v]> dij+p) {
                    di[v] = dij+p;
                    pq.push({di[v],v});
                }
            }
        }
        d.push_back(di);
    }
    vector<pli> dp(n,{1e18,0});
    dp[0] = {0,-k};
    set<int> blm;
    rep(i,0,n) {
        blm.insert(i);
    }
    priority_queue<plii,vector<plii>,greater<plii>> pq;
    pq.push({dp[0],0});
    while(sz(pq)) {
        auto [di, i] = pq.top(); pq.pop();
        if(dp[i]<di) continue;
        blm.erase(i);
        if(i==n-1) break;
        auto [cs, ki] = di;
        ki *= -1;
        for(auto v: blm) {
            ll csn = 1e18;
            int kin = 0;
            if(d[i][v]<=ki) {
                csn = cs;
                kin = ki-d[i][v];
            } else {
                csn = cs + 1ll*t[i]*(d[i][v]-ki);
            }
            if(pli{csn,-kin}<dp[v]) {
                dp[v] = {csn, -kin};
                pq.push({dp[v],v});
            }
        }
    }
    if(dp[n-1].fi > mc) {
        cout <<"muak gweh, butuh heal lagi\n";
    } else {
        cout <<dp[n-1].fi <<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}