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

const int mxn=2e5;
int n;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i]; a[i]--;
    }
    vector v(n,vi());
    rep(i,0,n) {
        v[a[i]].push_back(i);
    }
    ll ans = 0;
    rep(i,0,n) {
        rep(j,0,sz(v[i])) {
            int le = (j>0?v[i][j-1]:-1);
            // int ri = (j+1<sz(v[i])?v[i][j+1]:n);
            int ri = n;
            int cur = v[i][j];
            ans += 1ll*(cur-le)*(ri-cur);
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