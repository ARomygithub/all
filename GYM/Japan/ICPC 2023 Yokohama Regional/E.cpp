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

const int mxn=24;
const ll mod = 998244353;
int n,m;
ll f[1<<mxn], g[1<<mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int a,b,c; cin >>a >>b >>c; a--,b--,c--;
        g[(1<<a)|(1<<c)]++;
        g[1<<b]++;
        g[(1<<a)|(1<<b)]--;
        g[(1<<b)|(1<<c)]--;
    }
    rep(i,0,n) {
        rep(S,0,(1<<n)) {
            if((S>>i)&1) {
                g[S] += g[S^(1<<i)];
            }
        }
    }
    f[0] = 1;
    rep(S,1,(1<<n)) {
        if(g[S]) continue;
        rep(i,0,n) {
            if((S>>i)&1) {
                f[S] = (f[S] + f[S^(1<<i)])%mod;
            }
        }
    }
    cout <<f[(1<<n)-1] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}