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

const ll mxn=1e14;
const int mxd=126;
ll n;
ll dg[mxd+1][10][14];

void solve() {
    cin >>n;
    for(ll i=1;i<=mxd;i++) {
        rep(j,0,10) {
            ll temp = 1;
            rep(k,0,14) {
                dg[i][j][k] = temp*j%i;
                temp =temp*10%i;
            }
        }
    }
    ll ans=0;
    if(n==mxn) {
        ans++;
        n--;
    }
    string sn="";
    rep(i,0,14) {
        sn +=(char)('0'+n%10);
        n /=10;
    }
    rep(i,1,mxd+1) {
        vector<vector<vector<ll>>> dp(i+1,vector<vector<ll>>(i,vector<ll>(2,0)));
        dp[0][0][1] = 1;
        per(j,13,-1) {
            vector<vector<vector<ll>>> dp_new(i+1,vector<vector<ll>>(i,vector<ll>(2,0)));
            rep(k,0,i+1) {
                rep(l,0,i) {
                    rep(m,0,2) {
                        rep(d,0,10) {
                            if(k+d>i) break;
                            if(m==1 && d>(sn[j]-'0')) break;
                            int l2 = (l + dg[i][d][j])%i;
                            int m2 = (m==1 && d==(sn[j]-'0'))?1 : 0;
                            dp_new[k+d][l2][m2] += dp[k][l][m];
                        }
                    }
                }
            }
            dp.swap(dp_new);
        }
        ans = (ans+dp[i][0][0]+dp[i][0][1]);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}