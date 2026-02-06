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
typedef pair<int,pii> pipi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,m;
string s[mxn];
vector<int> adjr[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
        rep(j,0,m) {
            if(i+j+1<n && s[i][j]=='1') {
                adjr[i+j+1].push_back(i);
            }
        }
    }
    vector<int> dp0(n,1e9), dpn(n,1e9);
    dp0[0] = 0;
    rep(i,0,n) {
        rep(j,0,m) {
            if(i+j+1<n && s[i][j]=='1') {
                min_self(dp0[i+j+1], dp0[i]+1);
            }
        }
    }
    dpn[n-1] = 0; 
    per(i,n-1,-1) {
        for(int v: adjr[i]) {
            min_self(dpn[v], dpn[i]+1);
        }
    }
    set<int> blm;
    rep(i,1,n-1) {
        blm.insert(i);
    }
    vector<int> ans(n-2,-1);
    set<pipi> e;
    rep(i,0,n) {
        rep(j,0,m) {
            if(i+j+1<n && s[i][j]=='1') {
                if(dp0[i]<(1e9) && dpn[i+j+1]<(1e9)) {
                    e.insert({dp0[i]+dpn[i+j+1]+1, {i, i+j+1}});
                }
            }
        }
    }
    for(auto [val, lr]: e) {
        auto [l,r] = lr;
        // cout <<l <<" " <<r <<" " <<val <<endl;
        auto it = blm.lower_bound(l+1);
        vector<int> apus;
        while(it!=blm.end() && (*it)<r) {
            ans[(*it)-1] = val;
            apus.push_back((*it));
            it++;
        }
        for(int u : apus) {
            blm.erase(u);
        }
    }
    rep(i,0,n-2) {
        cout <<ans[i] <<" \n"[i==n-3];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}