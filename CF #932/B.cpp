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

const int mxn=1e5;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    int mex = 0;
    set<int> s;
    rep(i,0,n) {
        cin >>a[i];
        s.insert(a[i]);
    }
    for(int u: s) {
        if(mex==u) mex++;
    }
    vector<pii> ans;
    s.clear();
    int mexi = 0;
    int l = 0;
    rep(i,0,n) {
        s.insert(a[i]);
        while(s.count(mexi)) {
            mexi++;
        }
        if(mexi==mex) {
            ans.push_back({l,i});
            l = i+1;
            // cout <<l <<"\n";
            s.clear();
            mexi = 0;
        }
    }
    if(sz(ans)) {
        if(ans.back().se !=n-1) {
            ans.back().se = n-1;
        }
    }
    if(sz(ans)>=2) {
        cout <<sz(ans) <<"\n";
        rep(i,0,sz(ans)) {
            cout <<ans[i].fi+1 <<" " <<ans[i].se+1 <<"\n";
        }
    } else {
        cout <<"-1\n";
    }
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