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

const int mxn=1e2+1;
int n,q;
int a[mxn][mxn][mxn];

void solve() {
    cin >>n;
    rep(i,1,n+1) {
        rep(j,1,n+1) {
            rep(k,1,n+1) {
                cin >>a[i][j][k];
            }
        }
    }
    rep(i,0,n) {
        rep(j,0,n+1) {
            rep(k,0,n+1) {
                a[i+1][j][k] += a[i][j][k];
            }
        }
    }
    rep(i,0,n+1) {
        rep(j,0,n) {
            rep(k,0,n+1) {
                a[i][j+1][k] += a[i][j][k];
            }
        }
    }
    rep(i,0,n+1) {
        rep(j,0,n+1) {
            rep(k,0,n) {
                a[i][j][k+1] += a[i][j][k];
            }
        }
    }
    cin >>q;
    while(q--) {
        int x1,x2,y1,y2,z1,z2; cin >>x1 >>x2 >>y1 >>y2 >>z1 >>z2;
        int ans = a[x2][y2][z2]-a[x1-1][y2][z2]-a[x2][y1-1][z2]-a[x2][y2][z1-1] + a[x1-1][y1-1][z2] + a[x1-1][y2][z1-1] + a[x2][y1-1][z1-1] - a[x1-1][y1-1][z1-1];
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}