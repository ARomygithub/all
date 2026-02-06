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

const int mxn=100;
int n,m;
int c[mxn],p[mxn];
double dp[mxn+1];

void solve() {
    cin >>n >>m;
    vector s(n, vector<int>());
    rep(i,0,n) {
        cin >>c[i] >>p[i];
        s[i].resize(p[i]);
        rep(j,0,p[i]) {
            cin >>s[i][j];
        }
    }
    rep(i,1,m+1) {
        dp[i] = 1e18;
        rep(j,0,n) {
            int ct=0;
            double atas = 0;
            rep(k,0,p[j]) {
                if(s[j][k]>0) {
                    ct++;
                    atas += dp[max(0,i-s[j][k])];
                }
                atas += 1.0*c[j];
            }
            min_self(dp[i], atas/(1.0*ct));
        }
    }
    cout <<fixed <<setprecision(8) << dp[m] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}