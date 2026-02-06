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

const int mxn=1e6;
const ll mod=1e9+7;
int n,m,q,t;

void solve() {
    cin >>n >>m;
    int x = min(50,min(n,m));
    vector a(x, vector(n, vector<int>(m)));
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>a[0][i][j];
        }
    }
    rep(xi,1,x) {
        rep(i,0,n-xi) {
            rep(j,0,m-xi) {
                int t1 = __gcd(a[xi-1][i][j], a[xi-1][i][j+1]);
                int t2 = __gcd(a[xi-1][i+1][j], a[xi-1][i+1][j+1]);
                a[xi][i][j] = __gcd(t1,t2);
            }
        }
    }
    cin >>q;
    ll f = 1;
    while(q--) {
        int x2,y2,k; cin >>x2 >>y2 >>k; x2--,y2--,k--;
        if(k<x) {
            // cout <<a[k][x2][y2] <<"\n";
            f = f*a[k][x2][y2]%mod;
        } else {
            int ans = 0;
            int d = x2+k, r = y2+k;
            for(int i=x2;i<=d;i+=x) {
                min_self(i, d-x+1);
                for(int j=y2;j<=r;j+=x) {
                    min_self(j, r-x+1);
                    ans = __gcd(ans, a[x-1][i][j]);
                }
            }
            // cout <<ans <<"\n";
            f = f*ans%mod;
        }
    }
    cout <<f <<"\n";
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