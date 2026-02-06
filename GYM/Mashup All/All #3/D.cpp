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

const int mxn=2e3;
const ll mod=1e9+7;
int n,m;
string s[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    if(n==1 && m==1) {
        cout <<"1\n";
        return;
    }
    vector srr(n, vi(m,0));
    rep(i,0,n) {
        per(j,m-1,-1) {
            if(j+1<m) {
                srr[i][j] += srr[i][j+1];
            }
            srr[i][j] += s[i][j]=='R';
        }
    }
    vector src(m, vi(n,0));
    rep(j,0,m) {
        per(i,n-1,-1) {
            if(i+1<n) {
                src[j][i] += src[j][i+1];
            }
            src[j][i] += s[i][j]=='R';
        }
    }
    vector dpr(m, vector<ll>(n,0)), dpd(n, vector<ll>(m,0));
    per(i,n-1,0) {
        per(j,m-1,0) {
            if(i+1<n) {
                ll dr = 0;
                // Rock dari j..m-1
                // down dari j..m-1-srr[i][j]
                int r = m-1-srr[i][j]+1;
                dr = dpd[i+1][j];
                if(r<m) {
                    dr = (dr - dpd[i+1][r] + mod)%mod;
                }
                dpr[j][i] = (dr + dpr[j][i+1])%mod;
            } else {
                ll dr = 0;
                if(srr[i][j]==0) {
                    dr = 1;
                }
                dpr[j][i] = dr;
            }
            if(j+1<m) {
                ll dd = dpr[j+1][i];
                int d = n-1-src[j][i]+1;
                if(d<n) {
                    dd = (dd - dpr[j+1][d] + mod)%mod;
                }
                dpd[i][j] = (dd + dpd[i][j+1])%mod;
            } else {
                ll dd = 0;
                if(src[j][i]==0) {
                    dd = 1;
                }
                dpd[i][j] = dd;
            }
        }
    }
    ll ans = 0;
    auto solver = [&](int i, int j) -> void {
        if(i+1<n) {
            ll dr = 0;
            // Rock dari j..m-1
            // down dari j..m-1-srr[i][j]
            int r = m-1-srr[i][j]+1;
            dr = dpd[i+1][j];
            if(r<m) {
                dr = (dr - dpd[i+1][r] + mod)%mod;
            }
            ans = (ans + dr)%mod;
        } else {
            ll dr = 0;
            if(srr[i][j]==0) {
                dr = 1;
            }
            ans = (ans + dr)%mod;
        }    
    };
    auto solved = [&](int i, int j) -> void {
        if(j+1<m) {
            ll dd = dpr[j+1][i];
            int d = n-1-src[j][i]+1;
            if(d<n) {
                dd = (dd - dpr[j+1][d] + mod)%mod;
            }
            ans = (ans + dd)%mod;
        } else {
            ll dd = 0;
            if(src[j][i]==0) {
                dd = 1;
            }
            ans = (ans + dd)%mod;
        }    
    };
    int i = 0, j = 1;
    if(j<m) {
        solver(i,j);
    }
    i = 1, j = 0;
    if(i<n) {
        solved(i,j);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}