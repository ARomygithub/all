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
ll n,t;

void solve() {
    cin >>n;
    vector<pii> ans;
    set<ll> s;
    if(n>1) {
        s.insert(n);
    }
    pll u = {n,n};
    while(u.fi>1) {
        ll bwh = min(u.fi/2,u.se/2);
        ll atas = max((u.fi+1)/2, (u.se+1)/2);
        u = {bwh,atas};
        if(bwh>1) {
            s.insert(bwh);
        }
        if(atas>1) {
            s.insert(atas);
        }
    }
    ans.push_back({-1,-1});
    map<ll,int> mp;
    mp[1] = 0;
    for(ll si : s) {
        ll l=(si+1)/2, r = si/2;
        ans.push_back({mp[l],mp[r]});
        mp[si] = sz(ans)-1;
    }
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i].fi <<" " <<ans[i].se <<"\n";
    }
    cout <<sz(ans)-1 <<"\n";
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