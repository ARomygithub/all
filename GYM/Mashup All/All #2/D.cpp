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

const int mxn=500;
const ll mod = 998244353;
int n,m;
int c[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        cin >>c[i];
    }
    vector dp(n, vector<ll>(n,0));
    vector vis(n, vector<bool>(n,0));
    function<ll(int,int)> getDp;
    getDp = [&](int l, int r) -> ll {
        if(vis[l][r-1]) return dp[l][r-1];
        vis[l][r-1] = 1;
        int mn = mxn+1, pos=-1;
        rep(i,l,r) {
            if(c[i]<mn) {
                mn = c[i];
                pos = i;
            }
        }
        ll temp1 = 0;
        per(l2,pos,l-1) {
            ll temp = 1;
            if(l2>l) {
                temp = temp*getDp(l,l2)%mod;
            }
            if(l2<pos) {
                temp = temp*getDp(l2,pos)%mod;
            }
            assert(temp>0);
            temp1 = (temp1+ temp)%mod;
        }
        ll temp2 = 0;
        rep(r2,pos+1,r+1) {
            ll temp = 1;
            if(r2>pos+1) {
                temp = temp*getDp(pos+1,r2)%mod;
            }
            if(r2<r) {
                temp = temp*getDp(r2,r)%mod;
            }
            // assert(temp>0);
            temp2 = (temp2 + temp)%mod;
        }
        dp[l][r-1] = (dp[l][r-1] + temp1*temp2%mod)%mod;
        // cout <<l <<" " <<r <<endl;
        // assert(dp[l][r-1]>0);
        return dp[l][r-1];
    };
    cout <<getDp(0,n) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}