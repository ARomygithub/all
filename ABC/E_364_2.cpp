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

const int mxn=80;
int n,x,y;
// int a[mxn],b[mxn];

void solve() {
    cin >>n >>x >>y;
    vector<int> a(n), b(n);
    rep(i,0,n) {
        cin >>a[i] >>b[i];
    }
    vector dp(n+1, vector<ll>(x+1,(int)(1e9)));
    int ans = 0;
    rep(i,0,x+1) {
        dp[0][i] = 0;
    }
    rep(i,0,n) {
        vector dp_new(n+1, vector<ll>(x+1,(int)(1e9)));
        rep(val,0,n+1) {
            rep(xi,0,x+1) {
                min_self(dp_new[val][xi], dp[val][xi]);
                if(dp[val][xi]>y) continue;
                max_self(ans, val+1);
                if(xi+a[i]>x) continue;
                min_self(dp_new[val+1][xi+a[i]], dp[val][xi]+b[i]); 
            }
        }
        per(val,n,-1) {
            rep(xi,0,x+1) {
                if(xi<x) {
                    min_self(dp_new[val][xi+1], dp_new[val][xi]);
                }
                if(val>0) {
                    min_self(dp_new[val-1][xi], dp_new[val][xi]);
                }
            }
        }
        dp.swap(dp_new);
    }
    assert(ans<=n);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}