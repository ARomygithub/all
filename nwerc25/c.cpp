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
int n,m;
vector<pii> adj[mxn];
int deg[mxn];
ll dp[mxn];
ll ans = 0;

void dfs(int u, int p =-1) {
    vector<ll> ch;
    for(auto [w,v]: adj[u]) {
        if(v==p) continue;
        dfs(v,u);
        if(dp[v]) {
            ch.push_back(dp[v]);
        }
    }
    // assert(sz(ch)<=2);
    for(int i=0;i+1<sz(ch);i+=2) {
        ans += ch[i]+ch[i+1];
    }
    ll cur = 0;
    if((sz(ch)%2)==1) {
        cur = ch.back();
        if(deg[u]) {
            ans += cur;
            cur = 0;
        } else {
            for(auto [w,v]: adj[u]) {
                if(v==p) {
                    cur += w;
                    break;
                }
            }
        }
    } else {
        if(deg[u]) {
            for(auto [w,v]:adj[u]) {
                if(v==p) {
                    cur += w;
                    break;
                }
            }
        }
    }
    dp[u] = cur;
}

void solve() {
    cin >>n;
    rep(i,1,n) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }

    cin >>m;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        deg[u] = (deg[u]+1)%2;
        deg[v] = (deg[v]+1)%2;
    }
    dfs(0,-1);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}