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

const int mxn=1e3;
int n;
int a[mxn], dp[mxn][mxn];
bool vis[mxn][mxn];

int getDp(int l, int r, int st=0) {
    if(vis[l][r]) return dp[l][r];
    vis[l][r] = 1;
    if(l==r) {
        if(st==0) {
            dp[l][r] = a[l];
        }
        return dp[l][r];
    }
    if(st) {
        dp[l][r] = min(getDp(l+1,r,1-st), getDp(l,r-1,1-st));
    } else {
        dp[l][r] = max(a[l]+getDp(l+1,r,1-st), getDp(l,r-1,1-st)+a[r]);
    }
    return dp[l][r];
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    cout <<getDp(0,n-1) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}