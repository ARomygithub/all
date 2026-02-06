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
int n,k;
ll m;

void solve() {
    cin >>n >>k >>m;
    ll ans = 0;
    vector cand(k, set<int>());
    rep(i,0,k) {
        cand[i*2%k].insert(i);
    } 
    rep(i,0,k) {
        if(sz(cand[i])==0) continue;
        vector dp(2, vector<ll>(k,0));
        dp[0][0] = 1;
        rep(j,0,n) {
            vector dp_new(2, vector<ll>(k,0));
            rep(l,0,2) {
                rep(o,0,k) {
                    rep(p,0,k) {
                        int nx = (o+p)%k;
                        int bn = l || cand[i].count(p);
                        dp_new[bn][nx] = (dp_new[bn][nx] + dp[l][o])%m; 
                    }
                }
            }
            dp.swap(dp_new);
        }
        ans = (ans + dp[1][i])%m;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}