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
using piii = pair<int,pii>;

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
    vector dp(n, vi(k+1,mc+1));
    dp[0][k] = 0;
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    pq.push({dp[0][k],{0,k}});
    while(sz(pq)) {
        auto [dpi,iki] = pq.top(); pq.pop();
        auto [i,ki] = iki;
        if(dp[i][ki]<dpi) continue;
        if(i==n-1) continue;
        // refill
        if(dpi+t[i]<=mc && ki+1<=k && dp[i][ki+1]>dpi+t[i]) {
            dp[i][ki+1] = dpi+t[i];
            pq.push({dp[i][ki+1],{i,ki+1}});
        }
        for(auto [p,v]: adj[i]) {
            if(ki>=p) {
                if(dp[v][ki-p] > dpi) {
                    dp[v][ki-p] = dpi;
                    pq.push({dp[v][ki-p],{v,ki-p}});
                }
            }
        }
    }
    int ans = mc+1;
    rep(i,0,k+1) {
        min_self(ans, dp[n-1][i]);
    }
    if(ans>mc) {
        cout <<"muak gweh, butuh heal lagi\n";
    } else {
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}