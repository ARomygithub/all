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

const int mxn=2e5;
int n;
vi adj[mxn];
ll sm[mxn][2], ct[mxn][2];
ll ans = 0;

void dfs(int u, int p) {
    ct[u][0]++;
    vector<ll> ctk(2,0);
    ll sm2=0;
    for(int v: adj[u]) {
        if(v==p) continue;
        dfs(v,u);
        ctk[0] += ct[v][1];
        ctk[1] += ct[v][0];
        sm2 += ct[v][0]*ct[v][0];
    }
    for(int v: adj[u]) {
        if(v==p) continue;
        ll od = sm[v][0];
        ans += od/2 + ct[v][0];
        ll ev = sm[v][1] + ct[v][1];
        ans += ev/2;
        sm[u][0] += ev;
        sm[u][1] += od+ct[v][0];
        ll sisa = (ctk[0]+ctk[1])-(ct[v][0]+ct[v][1]);
        ans += (ev/2)*sisa;
        ans += (od/2 + ct[v][0])*sisa;
    }
    ct[u][0] += ctk[0];
    ct[u][1] += ctk[1];
    ans -= (ctk[1]*ctk[1] - sm2)/2;
}

void solve() {
    cin >>n;
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
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