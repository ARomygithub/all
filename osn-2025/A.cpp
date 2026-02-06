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
int n,m,q,t;
vector<pii> adj[2][mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v,w,z; cin >>u >>v >>w >>z; u--,v--, z--;
        adj[z][u].push_back({w,v});
        adj[z][v].push_back({w,u});
    }
    int inf = 2e9;
    vi dp1(n,inf);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dp1[0] = 0;
    pq.push({0,0});
    while(sz(pq)) {
        auto [d,u] = pq.top(); pq.pop();
        if(dp1[u]<d) continue;
        rep(z,0,2) {
            for(auto [w,v]: adj[z][u]) {
                if(dp1[v] > d+w) {
                    dp1[v] = d+w;
                    pq.push({d+w,v});
                }
            }
        }
    }
    vi dp2(n,inf);
    dp2[n-1] = 0;
    pq.push({0,n-1});
    while(sz(pq)) {
        auto [d,u] = pq.top(); pq.pop();
        if(dp2[u]<d) continue;
        for(auto [w,v]: adj[1][u]) {
            if(dp2[v] > d+w) {
                dp2[v] = d+w;
                pq.push({d+w,v});
            }
        }
    }
    vector<pii> v;
    rep(i,0,n) {
        if(dp1[i]==inf || dp2[i]==inf) continue;
        v.push_back({dp1[i],dp1[i]+dp2[i]});
    }
    sort(all(v));
    vector<pii> ans;
    for(auto& [a,ab]: v) {
        if(sz(ans)) {
            if(ab < ans.back().se) {
                ans.push_back({a,ab});
            }
        } else {
            ans.push_back({a,ab});
        }
    }
    cin >>q;
    while(q--) {
        int ti; cin >>ti;
        auto it = upper_bound(all(ans), pii{ti,inf});
        if(it==ans.begin()) {
            cout <<"-1\n";
        } else {
            it--;
            cout <<(it->se) <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}