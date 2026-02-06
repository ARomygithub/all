#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i< (b); ++i)
#define per(i, a, b) for(int i = a; i> (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
#define fi first
#define se second

const int di[] = {-1,1}, dj[] = {-1,1};
const int mxn = 500;
int n,a,b,c,d;
bool f[mxn][mxn][2];

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<n;
}

void rec(int i, int j, int k) {
    if(f[i][j][k]) return;
    f[i][j][k] = 1;
    if(k) {
        // a b
        rep(li,0,2) {
            rep(lj,0,2) {
                int ii = i + di[li]*a;
                int jj = j + dj[lj]*b;
                if(e(ii,jj)) {
                    rec(ii,jj,1-k);
                }
            }
        }
        rep(li,0,2) {
            rep(lj,0,2) {
                int ii = i + di[li]*b;
                int jj = j + dj[lj]*a;
                if(e(ii,jj)) {
                    rec(ii,jj,1-k);
                }
            }
        }        
    } else {
        // c d
        rep(li,0,2) {
            rep(lj,0,2) {
                int ii = i + di[li]*c;
                int jj = j + dj[lj]*d;
                if(e(ii,jj)) {
                    rec(ii,jj,1-k);
                }
            }
        }
        rep(li,0,2) {
            rep(lj,0,2) {
                int ii = i + di[li]*d;
                int jj = j + dj[lj]*c;
                if(e(ii,jj)) {
                    rec(ii,jj,1-k);
                }
            }
        }                
    }
}

void solve() {
    cin >>n;
    cin >>a >>b >>c >>d;
    rec(0,0,1);
    rec(0,0,0);
    int ans = 0;
    rep(i,0,n) {
        rep(j,0,n) {
            ans += (f[i][j][0] || f[i][j][1]);
        }
    }
    cout <<ans <<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    solve();
}