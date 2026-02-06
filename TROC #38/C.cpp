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
const ll mod = 998244353;
int n,m;
bool a[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int ai; cin >>ai; ai--;
        a[ai] = 1;
    }
    vector<ll> ans(2,0);
    ans[1] = 1;
    rep(i,0,n) {
        if(a[i]) {
            ans[1] = ans[0];
            ans[0] = 0;
        } else {
            ll ab1 = (ans[0]+ans[1])%mod;
            ll ab2 = (ab1+ans[0])%mod;
            ans[0] = ab2;
            ans[1] = ab1;
        }
    }
    cout <<ans[0] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}