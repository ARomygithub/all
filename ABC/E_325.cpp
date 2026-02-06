#include <bits/stdc++.h>
using namespace std;

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e3;
ll n,a,b,c;
vector<pll> adj1[mxn];
vector<pll> adj2[mxn];

void solve() {
    cin >>n >>a >>b >>c;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ll d; cin >>d;
            if(j>i) {
                adj1[i].push_back({d*a,j});
                adj1[j].push_back({d*a,i});
                adj2[i].push_back({d*b+c,j});
                adj2[j].push_back({d*b+c,i});
            }
        }
    }
    vector<ll> dp1(n,1e18), dp2(n,1e18);
    priority_queue<pll,vector<pll>,greater<pll>> pq1, pq2;
    dp1[0] = 0;
    pq1.push({0ll,0ll});
    while(sz(pq1)) {
        auto [d,u] = pq1.top(); pq1.pop();
        if(dp1[u]<d) continue;
        for(auto [w,v]: adj1[u]) {
            if(dp1[v]>d+w) {
                dp1[v] = d+w;
                pq1.push({dp1[v],v});
            }
        }
    }
    dp2[n-1] = 0;
    pq2.push({0ll,n-1});
    while(sz(pq2)) {
        auto [d,u] = pq2.top(); pq2.pop();
        if(dp2[u]<d) continue;
        for(auto [w,v]: adj2[u]) {
            if(dp2[v]>d+w) {
                dp2[v] = d+w;
                pq2.push({dp2[v],v});
            }
        }
    }
    ll ans=1e18;
    for(int i=0;i<n;i++) {
        min_self(ans,dp1[i]+dp2[i]);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}