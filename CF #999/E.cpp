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

const int mxn=1e5,mxm=10;
int n,m,k,t;
int a[mxn],b[mxm];

void solve() {
    cin >>n >>m >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,m) {
        cin >>b[i];
    }
    vi sb(1<<m,(1<<30)-1);
    rep(bit,0,(1<<m)) {
        rep(j,0,m) {
            if((bit>>j)&1) {
                sb[bit] = sb[bit]&b[j];
            }
        }
    }
    vector va(n, vi(m+1,(1<<30)));
    rep(i,0,n) {
        rep(bit,0,(1<<m)) {
            int ct = __builtin_popcount(bit);
            min_self(va[i][ct], a[i]&sb[bit]);
        }
    }
    multiset<int> ms;
    rep(i,0,n) {
        rep(j,1,m+1) {
            int dif = va[i][j-1]-va[i][j];
            ms.insert(dif);
        }
    }
    ll ans = 0;
    rep(i,0,n) {
        ans += a[i];
    }
    while(sz(ms) && k>0) {
        auto it = --ms.end();
        k--;
        ans -= (*it);
        ms.erase(it);
    }
    cout <<ans <<"\n";
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