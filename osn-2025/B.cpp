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

const int mxn=2e5;
int n,k,t;
ll a[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    int lbh = 0;
    if(k>18) {
        lbh = k - 18;
        k = 18;
    }
    bool gede = lbh >= 18;
    rep(i,0,min(mxn,(1<<k))) {
        ll bit = 0;
        rep(j,0,k) {
            if((i>>j)&1) {
                bit += (1<<(k-1-j));
            }
        }
        ll sm = 0;
        ll ats = bit*n+n;
        ll ct = 0;
        for(ll j = bit*n; j < bit*n+n;) {
            ll id = j / (1<<k);
            ll bts = (id+1)*(1<<k) - 1;
            ll cur = min(ats-1,bts) - j + 1;
            if(gede || n-ct <= cur*(1<<lbh)) {
                sm += a[id]*(n-ct);
                break;
            } else {
                sm += cur*(1<<lbh)*a[id];
                ct += cur*(1<<lbh);
            }
            // sm += cur*a[id];
            j += cur;
        }
        cout <<sm <<"\n";
    }
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