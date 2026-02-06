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
int n;
string t;

void solve() {
    cin >>t;
    cin >>n;
    vector v(n, vector<string>());
    rep(i,0,n) {
        int ai; cin >>ai;
        v[i].resize(ai);
        rep(j,0,ai) {
            cin >>v[i][j];
        }
    }
    vector<int> dp(sz(t)+1,1e9);
    dp[0] = 0;
    rep(i,0,n) {
        per(j,sz(t),0) {
            rep(k,0,sz(v[i])) {
                if(j>=sz(v[i][k])) {
                    if(t.substr(j-sz(v[i][k]), sz(v[i][k])) == v[i][k]) {
                        min_self(dp[j], dp[j-sz(v[i][k])]+1);
                    }
                }
            }
        }
    }
    if(dp[sz(t)]==1e9) {
        cout <<"-1\n";
    } else {
        cout <<dp[sz(t)] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}