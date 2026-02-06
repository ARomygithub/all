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

const int mxn=1e5;
int n;
ll a[mxn],k;

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    ll ans = 0;
    int ct=0;
    while((1ll<<(ct+1))-1<k) {
        ct++;
    }
    vector ac(ct+1, vector<ll>(2,0));
    rep(i,0,n) {
        rep(j,0,ct+1) {
            ac[j][(a[i]>>j)&1]++;
        }
        ans += (a[i]>>(ct+1))<<(ct+1);
    }
    vector dp(ct+1, vector(2, vector<ll>(2,-1e18)));
    rep(i,0,2) {
        if(i> ((k>>ct)&1)) continue;
        bool strict = (i==((k>>ct)&1));
        dp[ct][i][strict] = ac[ct][i^1]*(1ll<<ct);
    }
    per(bit,ct,0) {
        rep(last,0,2) {
            rep(j,0,2) {
                int bitn = bit-1;
                int curn = (k>>(bitn))&1;
                int jn = (j==1 && curn==0);
                max_self(dp[bitn][0][jn], dp[bit][last][j]+(1ll<<bitn)*ac[bitn][1]);
                if(curn==0 && j==1) continue;
                jn = (j==1 && curn==1);
                max_self(dp[bitn][1][jn], dp[bit][last][j]+(1ll<<bitn)*ac[bitn][0]);
            }
        }
    }
    ll mx = -1e18;
    rep(i,0,2) {
        rep(j,0,2) {
            max_self(mx, dp[0][i][j]);
        }
    }
    cout <<ans+mx <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}