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

const int mxn=16;
int n;
string s[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>s[i];
    }
    vector dp((1<<n), vector<bool>(n+1, 0));
    // dp[(1<<n)-1] = 0;
    per(i,(1<<n)-2,-1) {
        rep(j,0,n+1) {
            // bool adaMove = 0;
            bool win = 0;
            rep(k,0,n) {
                if(((i>>k)&1)==0 && (j==n || s[j][sz(s[j])-1]==s[k][0])) {
                    if(dp[i|(1<<k)][k]==0) {
                        win = 1;
                        break;
                    }
                }
            }
            dp[i][j] = win;
        }
    }
    if(dp[0][n]) {
        cout <<"First\n";
    } else {
        cout <<"Second\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}