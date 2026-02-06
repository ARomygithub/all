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

const int mxn=500;
int n;
int a[mxn+1];

void solve() {
    cin >>n;
    rep(i,1,n+1) {
        cin >>a[i];
    }
    vector dp(n+1,vector<int>(n+1,0));
    rep(len,3,n+1) {
        rep(i,1,n-len+2) {
            int ir = i+len-1;
            max_self(dp[i][ir],dp[i][ir-1]);
            for(int j=ir-3;j+1>=i;j-=3) {
                int temp = a[j+1]+a[ir] + dp[i][j];
                for(int i2=j+2;i2<ir;i2+=3) {
                    max_self(dp[i][ir], temp+a[i2]+dp[j+2][i2-1] + dp[i2+1][ir-1]);
                }
            }
            // cout <<i <<" " <<ir <<endl;
            // cout <<dp[i][ir] <<endl; 
        }
    }
    cout <<dp[1][n] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}