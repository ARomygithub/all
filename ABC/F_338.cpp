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
typedef pair<ll,pii> plii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=20;
const ll inf = 1e18;
int n,m;

void solve() {
    cin >>n >>m;
    vector dist(n, vector<ll>(n,inf));
    rep(i,0,m) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        dist[u][v] = w; 
    }
    rep(i,0,n) dist[i][i] = 0ll;
    rep(k,0,n) rep(i,0,n) rep(j,0,n)
        if(dist[i][k] != inf && dist[k][j]!=inf) {
            min_self(dist[i][j], dist[i][k]+dist[k][j]);
        }
    vector dp((1<<n),vector<ll>(n, inf));
    rep(i,0,n) {
        dp[(1<<i)][i] = 0;
    }
    rep(i,1,(1<<n)) {
        rep(j,0,n) {
            if(dp[i][j] == inf) continue;
            if(i&(1<<j)) {
                rep(k,0,n) {
                    if(i&(1<<k)) continue;
                    if(dist[j][k] == inf) continue;
                    min_self(dp[i | (1<<k)][k], dp[i][j]+dist[j][k]); 
                }
            }
        }
    }
    ll ans = 1e18;
    rep(i,0,n) {
        min_self(ans, dp[(1<<n)-1][i]);
    }
    if(ans == 1e18) {
        cout <<"No\n";
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