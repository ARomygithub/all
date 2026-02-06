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
int n,t;
int a[mxn][2];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i][0] >>a[i][1];
    }
    vi idx(n);
    iota(all(idx),0);
    sort(all(idx), [&](int i, int j) -> bool {
        return pii{max(a[i][0],a[i][1]),min(a[i][0],a[i][1])}<pii{max(a[j][0],a[j][1]),min(a[j][0],a[j][1])};
    });
    rep(i,0,n) {
        rep(j,0,2) {
            cout <<a[idx[i]][j] <<" \n"[i==n-1 && j==1];
        }
    }
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