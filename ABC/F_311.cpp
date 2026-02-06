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

const int mxn=2e3;
const ll mod = 998244353;
int n,m;
string s[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    vector<int> mn(n+m-1,1e9);
    rep(ij,1-m,n) {
        min_self(mn[ij+m-1], min(m,n-ij));
        per(j,min(m,n-ij)-1,max(-ij-1,-1)) {
            if(s[j+ij][j]=='#') {
                min_self(mn[ij+m-1], j);
            }
        }
    }
    vector dp(n+m-1, vector<ll>(m+1,0));
    rep(ij,1-m,n) {
        if(ij==1-m) {
            dp[0][m] = s[0][m-1]=='.';
            dp[0][m-1] = 1;
            continue;
        }
        ll temp = 0;
        per(j,m,max(-ij-1,-1)) {
            temp = (temp + dp[ij+m-1-1][j])%mod;
            if(j<=mn[ij+m-1]) {
                dp[ij+m-1][j] = (dp[ij+m-1][j]+temp)%mod;
                // cout <<j+ij <<" " <<j <<'\n';
                // cout <<dp[ij+m-1][j] <<"\n";
            }
        }
    }
    ll ans = 0;
    per(j,min(m,n-(n-1)),-1) {
        ans = (ans+ dp[n-1+m-1][j])%mod;
        // cout <<n-1 <<" " <<j <<"\n";
        // cout <<dp[n-1+m-1][j] <<"\n";
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}