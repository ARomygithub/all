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

const int mxn=22;
int n;
ll c,a[mxn],b[mxn];

void solve() {
    cin >>n >>c;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    vector<ll> dp(1<<n,1e18);
    dp[0] = c*-1;
    rep(s,0,(1<<n)) {
        int skrg=__builtin_popcount(s);
        rep(l,0,n) {
            ll cost = c;
            for(int r=l,i=skrg;r<n;i++,r++) {
                if((s>>r)&1) {
                    break;
                }
                cost += abs(a[r]-b[i]);
                min_self(dp[s | ((1<<(r+1))-(1<<(l)))], dp[s]+cost);
            }
        }
    }
    cout <<dp[(1<<n)-1] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}