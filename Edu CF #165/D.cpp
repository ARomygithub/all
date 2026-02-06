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

const int mxn=2e5;
int n,k,t;
pii ba[mxn];

void solve() {
    cin >>n >>k;
    ll ans = 0;
    rep(i,0,n) {
        cin >>ba[i].se;
    }
    rep(i,0,n) {
        cin >>ba[i].fi;
    }
    sort(ba,ba+n, greater<pii>());
    vector<ll> prof(n,0);
    per(i,n-1,-1) {
        prof[i] = (i+1<n?prof[i+1]:0ll) + (ba[i].fi-ba[i].se>0?ba[i].fi-ba[i].se:0ll);
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    ll s = 0;
    if(sz(pq)==k) {
        max_self(ans, s + prof[0]);
    }
    rep(i,0,n-1) {
        pq.push(ba[i].se*-1);
        s -= ba[i].se;
        while(sz(pq)>k) {
            auto temp = pq.top(); pq.pop();
            s -= temp;
        }
        if(sz(pq)==k) {
            max_self(ans, s + prof[i+1]);
        }
    }
    cout <<ans <<"\n";
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