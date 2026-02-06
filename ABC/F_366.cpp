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
int n,k;

void solve() {
    cin >>n >>k;
    vector<pii> ab(n);
    rep(i,0,n) {
        cin >>ab[i].fi >>ab[i].se;
    }
    sort(ab.begin(),ab.end(), [&](pii p1, pii p2) -> bool {
        ll s1 = 1ll*(p1.fi-1)*p2.se;
        ll s2 = 1ll*(p2.fi-1)*p1.se;
        return s1<s2;
    });
    vector<ll> dp(k+1, 0);
    dp[0] = 1;
    rep(i,0,n) {
        auto [a,b] = ab[i];
        vector<ll> dp_new(k+1,0);
        rep(j,0,k+1) {
            max_self(dp_new[j], dp[j]);
            if(j<k) {
                max_self(dp_new[j+1], dp[j]*a+b);
            }
        }
        dp.swap(dp_new);
    }
    cout <<dp[k] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}