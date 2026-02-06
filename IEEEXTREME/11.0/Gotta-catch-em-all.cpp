#include <bits/stdc++.h>
using namespace std;

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

const int mxn=2e2;
int r,c;
int a[mxn][mxn];

void solve() {
    cin >>r >>c;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cin >>a[i][j];
        }
    }
    vector<vector<int>> dp(r,vector<int>(c));
    for(int i=r-1;i>=0;i--) {
        for(int j=c-1;j>=0;j--) {
            if(i==r-1 && j==c-1) {
                dp[i][j] = 1+max(0,a[i][j]*-1);
            } else {
                dp[i][j] = 1e9;
                if(i+1<r) {
                    min_self(dp[i][j],max(1+max(0,a[i][j]*-1),dp[i+1][j]-a[i][j]));
                }
                if(j+1<c) {
                    min_self(dp[i][j],max(1+max(0,a[i][j]*-1),dp[i][j+1]-a[i][j]));
                }
            }
        }
    }
    cout <<dp[0][0] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}