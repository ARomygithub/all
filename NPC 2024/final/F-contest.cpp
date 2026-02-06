#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
#define fi first
#define se second


const int mxn = 1e5;
ll n,m,k,mc;
using pli = pair<ll,ll>;
using plii = pair<pli,ll>;

void solve() {
    cin >>n >>m >>k >>mc;
    vector adj(n, vector<pii>());
    vi t(n,0);
    rep(i,0,m) {
        ll u,v,c; cin >>u >>v >>c; u--,v--;
        ll p = abs(u-v);
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
    vector d(n, vi());
    rep(i,0,n) {
        vi di(n,1e9);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        di[i] = 0;
        pq.push({di[i],i});
        while(sz(pq)) {
            auto [dij, j] = pq.top(); pq.pop();
            if(di[j]<dij) continue;
            for(auto [p,v]: adj[j]) {
                if(di[v]>dij+p) {
                    di[v] = dij+p;
                    pq.push({di[v],v});
                }
            }
        }
        d[i].swap(di);
    }
    vector<pli> dp(n,{1e18,0});
    dp[0] = {0,-k};
    set<ll> blm;
    rep(i,0,n) {
        blm.insert(i);
    }
    priority_queue<plii,vector<plii>,greater<plii>> pq;
    pq.push({dp[0],0});
    while(sz(pq)) {
        auto [di, i] = pq.top(); pq.pop();
        if(dp[i]<di) continue;
        // blm.erase(i);
        if(i==n-1) break;
        auto [cs, ki] = di;
        ki *= -1;
        for(auto v: blm) {
            ll csn = 1e18;
            ll kin = 0;
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