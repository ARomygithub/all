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
typedef pair<pii,pii> pipi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=100;
int n,m,t;
string s[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    if(s[0][0]=='1') {
        cout <<"-1\n";
        return;
    }
    vector<pipi> ans;
    rep(i,0,n) {
        per(j,m-1,0) {
            if(s[i][j]=='1') {
                ans.push_back({{i,j-1},{i,j}});
            }
        }
    }
    per(i,n-1,0) {
        if(s[i][0]=='1') {
            ans.push_back({{i-1,0},{i,0}});
        }
    }
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i].fi.fi+1 <<" " <<ans[i].fi.se+1 <<" " <<ans[i].se.fi+1 <<" " <<ans[i].se.se+1 <<"\n";
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