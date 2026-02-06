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
typedef pair<pii,int> piii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5,mxk=10;
int n,m,q;
vector<int> adj[mxn];
int ans[mxn];
bool flag[mxn][mxk+1];

void func(pii vd, int c) {
    auto [v,d] = vd;
    if(flag[v][d]) return;
    flag[v][d] = 1;
    if(d==0) {
        ans[v] = c;
    } else {
        func({v,d-1}, c);
        for(int w: adj[v]) {
            func({w,d-1}, c);
        }
    }
}

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >>q;
    vector<piii> qry;
    rep(i,0,q) {
        int v,d,c; cin >>v >>d >>c; v--;
        qry.push_back({{v,d},c});
    }
    per(i,q-1,-1) {
        func(qry[i].fi, qry[i].se);
    }
    rep(i,0,n) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}