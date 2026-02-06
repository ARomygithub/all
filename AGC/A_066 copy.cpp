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
typedef pair<int,pii> ipii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=500;
const int di[4] = {-1,0,1,0}, dj[4]= {0,1,0,-1};
int n,d;
int a[mxn][mxn];

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<n;
}

void solve() {
    cin >>n >>d;
    rep(i,0,n) {
        rep(j,0,n) {
            cin >>a[i][j];
        }
    }
    rep(k,0,d*2) {
        int cost = 0;
        vector ans(n, vector<int>(n, -1e9));
        rep(i,0,n) {
            rep(j,0,n) {
                int r;
                if((i+j)%2) {
                    r = (a[i][j] -k -d)%(d*2);
                } else {
                    r = (a[i][j]-k)%(d*2);
                }
                r = (r+d*2)%(d*2);
                if(r<= d*2-r) {
                    ans[i][j] = a[i][j] - r;
                    cost += r;
                } else {
                    ans[i][j] = a[i][j] + d*2-r;
                    cost += d*2-r;
                }
            }
        }
        if(cost<=n*n*d/2) {
            // cout <<cost <<endl;
            rep(i,0,n) {
                rep(j,0,n) {
                    cout <<ans[i][j] <<" \n"[j==n-1];
                }
            }
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}