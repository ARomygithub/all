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

const int mxn=3e5;
const ll mod = 998244353;
int n,m,t;

void solve() {
    cin >>n >>m;
    vector<string> vs(n);
    int w = 0;
    rep(i,0,n) {
        cin >>vs[i];
        rep(j,0,m) {
            w += (vs[i][j]=='o');
        }
    }
    vector<ll> p2(w+1);
    p2[0] = 1;
    rep(i,1,w+1) {
        p2[i] = p2[i-1]*2%mod;
    }
    vector<pll> vc(max(n,m)+1);
    vc[0] = {1,0};
    rep(i,1,sz(vc)) {
        vc[i] = {(vc[i-1].fi + vc[i-1].se*2)%mod, vc[i-1].fi};
    }

    ll ans = 0;
    rep(i,0,n) {
        int ct = 0;
        rep(j,0,m-1) {
            if(vs[i][j]=='o' && vs[i][j+1]=='o') {
                ll cur = vc[ct].fi*p2[w-ct-2]%mod;
                ans = (ans + cur)%mod;
            }
            if(vs[i][j]=='o') {
                ct += (vs[i][j]=='o');
            } else {
                ct = 0;
            }
        }
    }
    rep(j,0,m) {
        int ct = 0;
        rep(i,0,n-1) {
            if(vs[i][j]=='o' && vs[i+1][j]=='o') {
                ll cur = vc[ct].fi*p2[w-ct-2]%mod;
                ans = (ans + cur)%mod;
            }
            if(vs[i][j]=='o') {
                ct += (vs[i][j]=='o');
            } else {
                ct = 0;
            }
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