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

const int mxn=300;
const ll mod=1e9+7;
int n;
int x[mxn],y[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>x[i] >>y[i];
    }
    ll ans = 0;
    vector dp(n+1, vector<ll>(n+1,0));
    dp[1][0] = x[n-1]==0;
    per(i,n-2,-1) {
        vector dp_new(n+1, vector<ll>(n+1,0));
        rep(ii,0,n+1) {
            rep(jj,0,n+1) {
                if(dp[ii][jj]==0) continue;
                rep(c,x[i],y[i]+1) {
                    if(c==0) {
                        if(ii<n) {
                            dp_new[ii+1][jj] = (dp_new[ii+1][jj] + dp[ii][jj])%mod;
                        }
                        if(jj>0) {
                            dp_new[ii][jj-1] = (dp_new[ii][jj-1] + dp[ii][jj]*jj%mod)%mod;
                        }
                    }
                    if(c==1) {
                        dp_new[ii][jj] = (dp_new[ii][jj] + dp[ii][jj]*ii*2%mod)%mod;
                        if(jj>0 && ii>1) {
                            dp_new[ii-1][jj-1] = (dp_new[ii-1][jj-1] + dp[ii][jj]*jj%mod *(ii-1)*2%mod)%mod;
                        }
                    }
                    if(c==2) {
                        if(ii>1) {
                            dp_new[ii-1][jj] = (dp_new[ii-1][jj] + dp[ii][jj]*ii%mod *(ii-1)%mod)%mod;
                        }
                        if(ii>2 && jj>0) {
                            dp_new[ii-2][jj-1] = (dp_new[ii-2][jj-1] + dp[ii][jj]*jj%mod *(ii-1)%mod *(ii-2)%mod)%mod;
                        }
                        if(jj<n) {
                            dp_new[ii][jj+1] = (dp_new[ii][jj+1] + dp[ii][jj]*ii*2%mod)%mod;
                        }
                        if(ii>1) {
                            dp_new[ii-1][jj] = (dp_new[ii-1][jj] + dp[ii][jj]*jj%mod *(ii-1)*2%mod)%mod;
                        }
                    }
                }
            }
        }
        dp.swap(dp_new);
    }
    // rep(j,0,n+1) {
    //     ans = (ans + dp[1][j])%mod;
    // }
    ans = dp[1][0];
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}