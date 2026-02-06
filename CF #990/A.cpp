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

const int mxn=5e3;
int n,t;
int a[2][mxn];

void solve() {
    cin >>n;
    rep(i,0,2) {
        rep(j,0,n) {
            cin >>a[i][j];
        }
    }
    ll ans = 0;
    multiset<int> ms;
    rep(j,0,n) {
        if(a[0][j]<=a[1][j]) {
            ans += a[1][j];
            ms.insert(a[0][j]);
        } else {
            ans += a[0][j];
            ms.insert(a[1][j]);
        }
    }
    ans += *(--ms.end());
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