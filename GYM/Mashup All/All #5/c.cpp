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

const int mxn=4,mxm=100;
int n,m,t;
int a[mxn][mxm];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>a[i][j];
        }
    }
    vi dp(1<<n, 0);
    rep(j,0,m) {
        vi dp_new(1<<n,0);
        rep(off,0,n) {
            rep(b1,0,1<<n) {
                rep(b2,0,1<<n) {
                    if((b1&b2)==0) {
                        int sm = 0;
                        rep(i,0,n) {
                            if((b2>>i)&1) {
                                sm += a[(i+off)%n][j];
                            }
                        }
                        max_self(dp_new[b1+b2], sm+dp[b1]);
                    }
                }
            }
        }
        dp.swap(dp_new);
    }
    cout <<dp[(1<<n)-1] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}