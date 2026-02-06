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
int n,p,q;
string s[mxn],a[mxn],b[mxn];

void solve() {
    cin >>n >>p >>q;
    rep(i,0,n) {
        cin >>s[i];
    }
    rep(i,0,p) {
        cin >>a[i];
    }
    rep(i,0,q) {
        cin >>b[i];
    }
    vector dp(p+1, vector(q+1,0));
    rep(ls,0,n) {
        per(i,p,-1) {
            per(j,q,-1) {
                if(i>0) {
                    int cur1 = (s[ls]==a[i-1]);
                    max_self(dp[i][j], dp[i-1][j]+cur1);
                } 
                if(j>0) {
                    int cur = (s[ls]==b[j-1]);
                    max_self(dp[i][j], dp[i][j-1]+cur);
                }
            }
        }
        rep(i,0,p+1) {
            rep(j,0,q+1) {
                if(i<p) {
                    max_self(dp[i+1][j], dp[i][j]);
                }
                if(j<q) {
                    max_self(dp[i][j+1], dp[i][j]);
                }
            }
        }
    }
    cout <<dp[p][q] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}