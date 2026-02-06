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
int n;
vi adj[mxn*2 + 1];

void solve() {
    cin >>n;
    vector<pii> vd;
    rep(i,0,n) {
        int d; cin >>d;
        vd.push_back({d,i+1});
    }
    sort(all(vd),greater<pii>());
    vi v(vd[0].fi+1);
    v[0] = (vd[0].se)*2-1;
    v.back() = (vd[0].se)*2;
    rep(i,1,sz(v)) {
        if(i==sz(v)-1) {
            adj[v[i-1]].push_back(v[i]);
        } else {
            v[i] = (vd[i].se)*2-1;
            adj[v[i-1]].push_back(v[i]);
        }
    }
    int idx = 1;
    int en = sz(v)-2;
    while(idx<=en) {
        int cur = (v[idx]+1)/2;
        int j = idx+vd[idx].fi;
        if(j>=sz(v)) {
            assert(j==sz(v));
            adj[v.back()].push_back(cur*2);
            v.push_back(cur*2);
        } else {
            adj[v[j-1]].push_back(cur*2);
        }
        idx++;
    }
    while(idx<sz(vd)) {
        auto [d, i] = vd[idx];
        adj[v[0]].push_back(2*i-1);
        if(d==1) {
            adj[2*i-1].push_back(2*i);
        } else {
            int j = d-2;
            assert(j<sz(v));
            adj[v[j]].push_back(2*i);
        }
        idx++;
    }
    rep(i,1,n+1) {
        int ii = i*2-1;
        for(auto u2: adj[ii]) {
            cout <<ii <<" " <<u2 <<"\n";
        }
        for(auto u2: adj[i*2]) {
            cout <<i*2 <<" "  <<u2 <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}