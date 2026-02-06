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

const int mxn=1e2;
int n,t;
string s;
const ll mod = 998244353;

void solve() {
    cin >>n;
    cin >>s;
    vector pr(n, vector<ll>(n+1,0)), suf(n, vector<ll>(n+1,0));
    vector pre(n, vector<ll>(n+1,0));
    map<char,int> mp;
    mp['('] = 1;
    mp[')'] = -1;
    rep(i,0,n) {
        if(i==0) {
            pr[i][0] = 1;
            if(s[i]=='(') {
                pr[i][1] = 1;
            }
            continue;
        }
        rep(j,0,n+1) {
            if(pr[i-1][j]==0) {
                continue;
            }
            pr[i][j] = (pr[i][j] + pr[i-1][j])%mod;
            int jn = j + mp[s[i]];
            if(jn>=0) {
                pr[i][jn] = (pr[i][jn] + pr[i-1][j])%mod;
            }
        }
    }
    per(i,n-1,-1) {
        if(i==n-1) {
            suf[i][0] = 1;
            if(s[i]==')') {
                suf[i][1] = 1;
            }
            continue;
        }
        rep(j,0,n+1) {
            if(suf[i+1][j]==0) continue;
            suf[i][j] = (suf[i][j] + suf[i+1][j])%mod;
            int jn = j - mp[s[i]];
            if(jn>=0) {
                suf[i][jn] = (suf[i][jn] + suf[i+1][j])%mod;
            }
        }
    }
    rep(i,1,n) {
        if(s[i]==')') {
            rep(j,1,n+1) {
                pre[i][j-1] = (pre[i][j-1] + pr[i-1][j])%mod;
            }
        }
    }
    rep(i,2,n) {
        rep(j,0,n+1) {
            pre[i][j] = (pre[i][j] + pre[i-1][j])%mod;
        }
    }
    ll ans = 0;
    rep(i,2,n) {
        if(s[i]!='(') continue;
        vector<ll> dp(pre[i-1]);
        per(j,n,0) {
            dp[j] = dp[j-1];
        }
        rep(j,i+1,n-1) {
            if(s[j]!='(') {
                rep(k2,1,n+1) {
                    dp[k2-1] = (dp[k2-1]+ dp[k2])%mod;
                }
            } else {
                rep(k,0,n) {
                    ans = (ans + dp[k]*suf[j+1][k+1]%mod)%mod;
                }
            }
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}