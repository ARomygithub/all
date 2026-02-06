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

const int mxn=5e4;
int n;

void solve() {
    cin >>n;
    vector<vector<int>> v(n);
    rep(i,0,n) {
        int m; cin >>m;
        v[i].resize(m);
        rep(j,0,m) {
            cin >>v[i][j];
        }
        sort(v[i].begin(),v[i].end());
    }
    ll ans = 0;
    int mn2 = 1e9, mn1=1e9;
    rep(i,0,n) {
        min_self(mn1, v[i][0]);
        int idx = min(sz(v[i])-1,1);
        min_self(mn2, v[i][idx]);
        ans += v[i][idx];
    }
    ans -= mn2-mn1;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >>t;
    while(t--) {
        solve();
    }
}