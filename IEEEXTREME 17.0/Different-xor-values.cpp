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

const int mxn=1e5,mxb=20;
const ll mod=1e9+7;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    ll ans=0;
    rep(ii,0,n) {
        vector<int> basis(mxb,0);
        int ukr = 0;
        // https://codeforces.com/blog/entry/68953?locale=en
        auto insertVector = [&](int mask) {
            for (int i = 0; i < mxb; i++) {
                if ((mask & 1 << i) == 0) continue;

                if (!basis[i]) {
                    basis[i] = mask;
                    ++ukr;
                    return;
                }

                mask ^= basis[i];
            }            
        };
        rep(j,ii,n) {
            insertVector(a[j]);
            ans = (ans + (1ll<<ukr))%mod;
        }
    }
    cout << ans <<"\n";
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