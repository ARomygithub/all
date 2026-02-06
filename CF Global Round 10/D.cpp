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

const int mxn=1e5;
int n,t;
string s;

void solve() {
    cin >>n;
    cin >>s;
    int ans = 1e9;
    string cc = "LR";
    rep(i,0,2) {
        rep(j,0,2) {
            vector dp(n, vector(2, vector<int>(2, 1e9)));
            rep(k,0,n) {
                if(k>0) {
                    rep(ki,0,2) {
                        rep(kj,0,2) {
                            if(kj==0) {
                                int temp = (s[k]==cc[ki]);
                                min_self(dp[k][ki][kj], dp[k-1][1-ki][0] + temp);
                                min_self(dp[k][ki][kj], dp[k-1][1-ki][1] + temp);
                            } else {
                                int temp = (s[k]==cc[ki]);
                                min_self(dp[k][ki][kj], dp[k-1][ki][kj-1] + temp);
                            }
                        }
                    }
                } else {
                    dp[0][1-i][0] = (s[k]==cc[1-i]);
                    if(j<1) {
                        dp[0][i][j+1] = (s[k]==cc[i]);
                    }
                }
            }
            min_self(ans, dp[n-1][i][j]);
        }
    }
    cout <<ans <<"\n";
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