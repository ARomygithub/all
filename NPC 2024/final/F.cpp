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

const int mxn=1e3;
int n,m,k,mc;
// n,m 1e3
// max_cap 5e4
// k 200
// c 1000
// t_i 200
vector<pii> adj[mxn];
int t[mxn];
using plli = pair<pll,int>;

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
    vector<pll> dp(n, {1e18,0});
    dp[0] = {0,-k};
    priority_queue<plli,vector<plli>,greater<plli>> pq;
    pq.push({dp[0],0});
    set<int> blm;
    rep(i,0,n) {
        blm.insert(i);
    }
    while(sz(pq)) {
        auto [dpi, i] = pq.top(); pq.pop();
        if(dp[i]<dpi) continue;
        auto [cs, ki] = dpi;
        blm.erase(i);
        if(i==n-1) break;
        ki *= -1;
        for(auto v: blm) {
            ll csn = 1e18;
            ll kin = 0;
            if(d[i][v]==1e9) continue; //ini ngaruh ga ya
            if(ki>=d[i][v]) {
                csn = cs;
                kin = ki-d[i][v];
            } else {
                csn = cs + (d[i][v]-ki)*t[i];
            }
            if(pll{csn,-kin}<dp[v]) {
                dp[v] = {csn,-kin};
                pq.push({dp[v],v});
            }
        }
    }
    if(dp[n-1].fi>mc) {
        cout <<"muak gweh, butuh heal lagi\n";
    } else {
        cout <<dp[n-1].fi <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}