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

const int mxn=15;
int n,d;
int w[mxn];

void solve() {
    cin >>n >>d;
    ll s = 0;
    rep(i,0,n) {
        cin >>w[i];
        s +=w[i];
    }
    vector dp(d+1, vector<ll>(1<<n,LLONG_MAX));
    dp[0][0] = 0;
    rep(i,1,d+1) {
        rep(j,0,1<<n) {
            if(i==1) {
                ll temp = 0;
                rep(k,0,n) {
                    if((j>>k)&1) {
                        temp += w[k];
                    }
                }
                temp *=temp;
                dp[i][j] = temp;
                continue;
            }
            int b = 0;
            do {
                min_self(dp[i][j], dp[i-1][j-b]+dp[1][b]);
            } while((b = ((b-j)&j)));
        }
    }
    s *=s;
    long double ans = ((long double)dp[d][(1<<n)-1])/((long double) d);
    d *=d;
    long double ans2 = ((long double)s)/((long double)(d));
    // cout <<fixed <<setprecision(8) <<ans2 <<"\n";
    // ans2 = ((long double)(1.0))*dp[d][(1<<n)-1]-ans2;
    // cout <<fixed <<setprecision(8) <<ans2 <<"\n";
    // ans2 *= ans2;
    ans = ans - ans2;
    cout <<fixed <<setprecision(10) <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}