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

const int mxn=20;
int n,m,t;
ll y, a[mxn];

void solve() {
    cin >>n >>m >>y;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<ll> g(1<<n,0);
    rep(bit,1,(1<<n)) {
        ll d = 1;
        rep(i,0,n) {
            if((bit>>i)&1) {
                ll dd = __gcd(d,a[i]);
                if(y/a[i] < d/dd) {
                    d = y+1;
                    break;
                }
                d = d/dd * a[i];
            }
        }
        g[bit] = y/d;
    }
    rep(i,0,n) {
        rep(S,0,(1<<n)) { 
            if((S>>i)&1) { g[S^(1<<i)] -= g[S]; } 
        } 
    }
    ll ans = 0;
    rep(bit,1,(1<<n)) {
        if(__builtin_popcountll(bit) == m) {
            ans += g[bit];
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}