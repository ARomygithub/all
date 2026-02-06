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

const int mxn=1e3;
ll n;
ll e[mxn][mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        rep(j,0,n) {
            cin >>e[i][j];
        }
    }
    vector<ll> sr(n),sc(n);
    rep(i,1,n-1) {
        sr[i] = ((e[i+1][0]-e[i][0])-(e[i][0]-e[i-1][0]))/2;
        sc[i] = ((e[0][i+1]-e[0][i])-(e[0][i]-e[0][i-1]))/2;
    }
    ll s = (e[n-1][n-1]+e[0][0])/(2ll*(n-1));
    ll r1c1,rnc1;
    {
        ll temp = e[0][n-1];
        rep(i,1,n-1) {
            temp -=1ll*i*sr[i];
        }
        rep(i,1,n-1) {
            temp -=1ll*i*sc[n-1-i];
        }
        rnc1 = temp/(n-1);
    }
    {
        ll temp = e[n-1][n-1];
        rep(i,1,n-1) {
            temp -=1ll*i*sr[n-1-i];
            temp -=1ll*i*sc[n-1-i];
        }
        r1c1 = temp/(n-1);
    }
    ll r1rn = s;
    rep(i,1,n-1) {
        r1rn -= sr[i];
    }
    sc[0] = (r1c1+rnc1-r1rn)/2;
    sr[0] = r1c1-sc[0];
    sr[n-1] = rnc1-sc[0];
    sc[n-1] = s;
    rep(i,0,n-1) {
        sc[n-1] -=sc[i];
    } 
    vector ans(n, vector<ll>(n,0));
    rep(i,0,n) {
        rep(j,0,n) {
            ll temp = min(sr[i],sc[j]);
            ans[i][j] = temp;
            sr[i] -= temp;
            sc[j] -= temp;
        }
    }
    rep(i,0,n) {
        rep(j,0,n) {
            cout <<ans[i][j] <<" \n"[j==n-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}