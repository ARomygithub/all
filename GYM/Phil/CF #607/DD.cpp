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

const int mxn=300;
int n,m;
string s[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(2,1e5)));
    dp[0][0][0] = 0, dp[0][0][1]=0;
    rep(i,0,n) {
        rep(j,0,m) {
            if(s[i][j]!='#') {
                if(i+1<n) {
                    if(s[i+1][j]!='#') {
                    min_self(dp[i+1][j][0], dp[i][j][0]);
                    min_self(dp[i+1][j][0], dp[i][j][1]+1);
                    }
                }
                if(j+1<m) {
                    if(s[i][j+1]!='#') {
                    min_self(dp[i][j+1][1], dp[i][j][0]+1);
                    min_self(dp[i][j+1][1], dp[i][j][1]);
                    }
                }
            }
        }
    }
    cout <<min(dp[n-1][m-1][0], dp[n-1][m-1][1]) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}