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
typedef pair<pii,int> piii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e4,mxa=1e5;
int n,m;
vector<pii> adj[mxn];
int ct[mxn];

void solve() {
    cin >>n >>m;
    vector<ll> v;
    v.push_back(1);
    vector<bool> isPrime(mxa,1);
    for(int i=2;i<mxa;i++) {
        if(isPrime[i]) {
            ll temp = v.back();
            if(i>((ll)(1e18))/temp) {
                break;
            }
            v.push_back(temp*i);
            for(int j=i*2;j<=mxa;j+=i) {
                isPrime[j] = 0;
            }
        }
    }
    vector<ll> v2;
    for(int i=0;i<n;i++) {
        ll id; cin >>id;
        v2.push_back(id);
    }
    sort(v2.begin(),v2.end());
    map<ll,int> mp;
    for(int i=0;i<n;i++) {
        mp[v2[i]] = i;
        ct[i] = upper_bound(v.begin(),v.end(),v2[i])-v.begin()-1;
    }
    for(int i=0;i<m;i++) {
        ll u,vi,w; cin >>u >>vi >>w;
        adj[mp[u]].push_back({w,mp[vi]});
        adj[mp[vi]].push_back({w,mp[u]});
    }
    vector<pii> dp(n, {2e9+1,0});
    dp[0] = {0,-1*ct[0]};
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    pq.push({{0,-1*ct[0]},0});
    while(sz(pq)) {
        auto [dg,u] = pq.top(); pq.pop();
        auto [d,g] = dg;
        if(dg>dp[u]) continue;
        for(auto [w,vi]: adj[u]) {
            if(make_pair(d+w,g-ct[vi])<dp[vi]) {
                dp[vi] = {d+w,g-ct[vi]};
                pq.push({dp[vi],vi});
            }
        }
    }
    cout <<dp[n-1].se*-1 <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}