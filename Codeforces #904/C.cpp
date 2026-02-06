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
    vector<pii> v1;
    rep(i,0,n) {
        int l,r; cin >>l >>r;
        v1.push_back({r,l});
        // v2.push_back({l,r});
    }
    // sort(v1.begin(),v1.end());
    // sort(v2.begin(),v2.end());
    int mx = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    rep(i,0,sz(v1)) {
        if(v1[i].fi < m) {
            pq.push({v1[i].se,1});
            pq.push({v1[i].fi+1,-1});
        }
    }
    int temp=0;
    while(sz(pq)) {
        auto [li,ct] = pq.top(); pq.pop();
        temp +=ct;
        max_self(mx,temp);
    }
    rep(i,0,sz(v1)) {
        if(v1[i].se > 1) {
            pq.push({v1[i].se,1});
            pq.push({v1[i].fi+1,-1});
        }
    }
    temp = 0;
    while(sz(pq)) {
        auto [li,ct] = pq.top(); pq.pop();
        temp +=ct;
        max_self(mx,temp);
    }
    cout <<mx <<"\n";
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