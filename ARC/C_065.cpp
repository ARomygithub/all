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
const string ds[4] = {"dream","dreamer","erase","eraser"};
int n;
string s;
bool dp[mxn+1];

void solve() {
    cin >>s;
    n = s.length();
    dp[0] = 1;
    rep(i,1,n+1) {
        rep(j,0,4) {
            if(sz(ds[j])<=i) {
                dp[i] |= ds[j]==s.substr(i-sz(ds[j]),sz(ds[j])) && dp[i-sz(ds[j])];
            }
        }
    }
    if(dp[n]) {
        cout <<"YES\n";
    } else {
        cout <<"NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}