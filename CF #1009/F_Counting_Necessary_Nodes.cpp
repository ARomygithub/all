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

const int mxn=1e5;
int l1,r1,l2,r2,t;

vi getv(int l, int r) {
    vi ret;
    while(l<r) {
        per(j,19,-1) {
            if(l%(1<<j)) {
                continue;
            }
            int ln = l + (1<<j);
            if(ln<=r) {
                ret.push_back((1<<j));
                l = ln;
                break;
            }
        }
    }
    return ret;
}

void solve() {
    cin >>l1 >>r1 >>l2 >>r2;
    vector<vi> v(2);
    v[0] =getv(l1,r1);
    v[1] = getv(l2,r2);
    ll ans = 0;
    rep(i,0,sz(v[0])) {
        rep(j,0,sz(v[1])) {
            ll cur = max(v[0][i],v[1][j])/min(v[0][i],v[1][j]);
            ans += cur;
        }
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