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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=400;
int n,m;
vector<pii> adj[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back({v,i});
    }
    vector<int> d0(n,1e5);
    vector<pii> l0(n,{-1,-1});
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    d0[0] = 0;
    pq.push({0,0});
    while(sz(pq)) {
        auto [d0i, u] = pq.top(); pq.pop();
        if(d0[u]<d0i) continue;
        for(auto [v,id]: adj[u]) {
            if(d0[v]>d0[u]+1) {
                d0[v] = d0[u]+1;
                l0[v] = {u,id};
                pq.push({d0[v],v});
            }
        }
    }
    vector<int> ans(m,(d0[n-1]>=1e5?-1:d0[n-1]));
    vector<int> block;
    int nn = n-1;
    while(l0[nn].fi!=-1) {
        block.push_back(l0[nn].se);
        nn = l0[nn].fi;
    }
    for(int blocked: block) {
        vector<int> d(n,1e5);
        priority_queue<pii,vector<pii>,greater<pii>> pq2;
        d[0] = 0;
        pq2.push({0,0});
        while(sz(pq2)) {
            auto [di,u] = pq2.top(); pq2.pop();
            if(d[u]<di) continue;
            for(auto [v,id]: adj[u]) {
                if(id==blocked) continue;
                if(d[v]>d[u]+1) {
                    d[v] = d[u]+1;
                    pq2.push({d[v],v});
                }
            }
        }
        ans[blocked] = d[n-1]>=1e5?-1:d[n-1];
    }
    rep(i,0,m) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}