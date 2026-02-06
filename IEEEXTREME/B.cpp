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
typedef pair<ll,int> pli;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,m,x,a,b;
vector<pii> adj[mxn];

void solve() {
    cin >>n >>m >>x >>a >>b;a--,b--;
    for(int i=0;i<m;i++) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    int ans=-1;
    int l=0,r=1e9;
    while(l<=r) {
        int mid=(l+r)/2;
        int speed = mid+1;
        vector<ll> dp(n,1e18);
        priority_queue<pli,vector<pli>,greater<pli>> pq;
        dp[a] = 0;
        pq.push({0,a});
        while(sz(pq)) {
            auto [w,v] = pq.top(); pq.pop();
            if(dp[v]<w) continue;
            for(auto [wi,ui]: adj[v]) {
                if(dp[ui]> dp[v]+(((wi+speed-1)/speed)+59)/60) {
                    dp[ui]  = dp[v]+(((wi+speed-1)/speed)+59)/60;
                    pq.push({dp[ui],ui});
                }
            }
        }
        if(dp[b]<=x) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}