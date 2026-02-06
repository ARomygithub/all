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
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e3;
int n,m,k;
int a[mxn][mxn];

void solve() {
    cin >>n >>m >>k;
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>a[i][j];
        }
    }
    ll ans = 0;
    vector<ll> v;
    rep(i,0,n) {
        ll sm = 0;
        rep(j,0,m) {
            sm += a[i][j];
        }
        rep(j,0,m) {
            sm -= a[i][j];
            ll cur = sm - 1ll*j*a[i][j];
            v.push_back(cur);
        }
    }
    sort(all(v), greater<ll>());
    rep(i,0,k) {
        ans += v[i];
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}