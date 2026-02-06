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

const int mxn=2e5;
int n;
string s;

void solve() {
    cin >>n;
    cin >>s;
    map<char,int> mp;
    mp['R'] = 0;
    mp['P'] = 1;
    mp['S'] = 2;
    vector dp(n, vector<int>(3,0));
    rep(i,0,n) {
        int cur = mp[s[i]];
        int mng = (cur+1)%3;
        int klh = (cur+2)%3;
        if(i==0) {
            dp[i][mng] = 1;
            continue;
        }
        rep(j,0,3) {
            if(j==klh) continue;
            int ct = (j==mng)+ max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
            max_self(dp[i][j], ct);
        }
    }
    int ans = 0;
    rep(i,0,3) {
        max_self(ans, dp[n-1][i]);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}