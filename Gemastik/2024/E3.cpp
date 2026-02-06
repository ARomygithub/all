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

const int mxn=1000;
const ll mod=1e9+7;
int n,k;
int a[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector go(n, vector(n, n));
    rep(i,0,n) {
        rep(j,i+1,n) {
            int sm = a[i]+a[j];
            int it = lower_bound(a,a+n,sm)-a;
            go[i][j] = it;
        }
    }
    // debug() <<imie(go);
    vector dp(n, vector<ll>(n,1));
    ll ans = 0;
    rep(len,2,62) {
        if(len>=k) {
            rep(i,0,n) {
                rep(j,i+1,n) {
                    ans = (ans + dp[i][j])%mod;
                }
            }
        }
        per(i,n-1,-1) {
            int j = i+1;
            int id = 0;
            ll temp = 0;
            while(j<n) {
                while(id<i && j==go[id][i]) {
                    temp = (temp + dp[id][i])%mod;
                    id++;
                }
                dp[i][j] = temp;
                j++;
            }
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