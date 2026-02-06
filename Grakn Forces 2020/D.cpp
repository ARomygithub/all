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

const int mxn=2e3;
int n,m;
int a[mxn],b[mxn],c[mxn],d[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i] >>b[i];
    }
    rep(i,0,m) {
        cin >>c[i] >>d[i];
    }
    vector<pii> v;
    rep(i,0,n) {
        rep(j,0,m) {
            if(c[j]>=a[i] && d[j]>=b[i]) {
                int x = c[j]-a[i]+1;
                int y = d[j]-b[i]+1;
                v.push_back({x,y});
            }
        }
    }
    sort(v.begin(),v.end());
    int mxy = 0;
    int ans = 1e9;
    per(i,sz(v)-1,-1) {
        min_self(ans, v[i].fi + mxy);
        max_self(mxy, v[i].se);
    }
    min_self(ans, mxy);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}