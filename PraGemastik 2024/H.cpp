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

const int mxn=1e3;
int n,m;
int p[mxn][mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>p[i][j];
        }
    }
    vector sum(n, vector(m, vector<ll>(3, 0ll)));
    per(i,n-1,-1) {
        rep(j,0,m) {
            sum[i][j][1] = p[i][j] + (i+1<n?sum[i+1][j][1]:0ll);
            sum[i][j][0] = p[i][j] + (i+1<n && j-1>=0? sum[i+1][j-1][0]:0ll);
            sum[i][j][2] = p[i][j] + (i+1<n && j+1<m? sum[i+1][j+1][2]:0ll);
        }
    }
    ll ans = 0;
    rep(j1,0,m) {
        rep(j2,j1+1,m) {
            ll temp = 0;
            rep(k,0,3) {
                temp += sum[0][j1][k];
                temp += sum[0][j2][k];
            }
            temp -= p[0][j1]*2;
            temp -= p[0][j2]*2;
            int ii = j2-j1;
            if(ii<n) {
                temp -= p[ii][j1];
            }
            if(((j2-j1)%2)==0) {
                int dif = j2-j1;
                ii = dif/2;
                int jj = j1+(dif/2);
                if(ii<n) {
                    temp -= p[ii][jj];
                }
            }
            ii = j2-j1;
            if(ii<n) {
                temp -= p[ii][j2];
            }
            // debug() <<imie(j1) <<imie(j2) <<imie(temp);
            max_self(ans, temp);
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}