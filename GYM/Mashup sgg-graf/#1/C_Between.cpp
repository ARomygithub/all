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
int n,m,t;

void solve() {
    cin >>n >>m;
    vector adj(n+1,vi());
    rep(i,0,m) {
        int u,v; cin >>u >>v;
        adj[v].push_back(u);
    }
    vi ct(n+1,-1);
    vi ord;
    queue<int> q;
    ct[1] = 1;
    q.push(1);
    while(sz(q)) {
        auto u = q.front(); q.pop();
        ord.push_back(u);
        for(int v: adj[u]) {
            if(ct[v]<0) {
                ct[v] = ct[u]+1;
                q.push(v);
            }
        }
    }
    rep(i,1,n+1) {
        if(ct[i]<0) {
            cout <<"INFINITE\n";
            return;
        }
    }
    reverse(all(ord));
    vi ans;
    rep(lvl,1,ct[ord[0]]+1) {
        rep(j,0,sz(ord)) {
            if(ct[ord[j]]<lvl) break;
            ans.push_back(ord[j]);
        }
    }
    cout <<"FINITE\n";
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<" \n"[i==sz(ans)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}