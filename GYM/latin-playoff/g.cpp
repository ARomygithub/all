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

const int mxn=1e5;
int n,w[mxn];

void solve() {
    cin >>n;
    ll sw = 0;
    rep(i,0,n) {
        cin >>w[i];
        sw += w[i];
    }
    vector<long double> dp(n+1);
    vi div(n+1,0);
    rep(i,1,n+1) {
        for(int j=i;j<=n;j+=i) {
            div[j] += w[i-1];
        }
    }
    per(i,n,0) {
        vi ct((n/i)+1,0);
        rep(j,1,sz(ct)) {
            ct[j] = div[j*i];
        }
        rep(j,1,sz(ct)) {
            for(int k=j*2;k<sz(ct);k+=j) {
                ct[k] -= ct[j];
            }
        }
        dp[i] = 0;
        rep(j,1,sz(ct)) {
            if(j==1) {
                dp[i] += 1.0L*ct[1]/sw;
                continue;
            }
            dp[i] += ct[j]*(dp[j*i]+1)/sw;
        }
        dp[i] *= 1.0L*sw/(sw-ct[1]);
    }
    cout <<fixed <<setprecision(15) <<dp[1] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}