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

const int mxn=25e4;
int n,k;
ll dp[mxn+1][10][10][3];
ll a[mxn+1];

void solve() {
    cin >>n >>k;
    rep(i,1,n+1) {
        cin >>a[i];
    }
    rep(j,0,k+1) {
        rep(l,0,k+1) {
            rep(m,0,3) {
                if(j!=l || m==2) {
                    dp[0][j][l][m] = 1e18;
                }
            }
        }
    }
    rep(i,1,n+1) {
        rep(j,0,k+1) {
            rep(l,0,k+1) {
                rep(m,0,3) {
                    ll &r = dp[i][j][l][m];
                    r = 1e18;
                    min_self(r, a[i]+dp[i-1][j][l][0]);
                    if(l!=k) min_self(r, dp[i-1][j][l+1][0]);
                    if(m!=2) {
                        min_self(r, dp[i-1][j][l][m+1]);
                        if(j!=k) min_self(r, a[i]+dp[i-1][j+1][l][m+1]);
                    }
                }
            }
        }
    }
    cout <<dp[n][0][0][1] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}