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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=10;
int n,m,t;
int a[mxn][mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>a[i][j];
        }
    }
    if(n==1 && m==1) {
        cout <<"-1\n";
        return;
    }
    vector b(n, vector<int>(m));
    rep(i,0,n) {
        rep(j,0,m) {
            int ii = i, jj = j;
            jj++;
            if(jj==m) {
                jj = 0;
                ii++;
            }
            if(ii==n) {
                ii = 0;
            }
            b[i][j] = a[ii][jj];
        }
    }
    rep(i,0,n) {
        rep(j,0,m) {
            cout <<b[i][j] <<" \n"[j==m-1];
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