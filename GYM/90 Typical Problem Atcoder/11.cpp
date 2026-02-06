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

const int mxn=5e3;
int n;
tuple<int,int,int> jb[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>get<0>(jb[i]) >>get<1>(jb[i]) >>get<2>(jb[i]);
    }
    sort(jb,jb+n);
    vector<ll> dp(mxn+1, 0);
    rep(i,0,n) {
        auto [d,c,s] = jb[i];
        per(j,d,c-1) {
            max_self(dp[j], dp[j-c]+s);
        }
    }
    ll ans = 0;
    rep(i,0,mxn+1) {
        max_self(ans, dp[i]);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}