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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=100;
int n,m,t;
string s[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    bool ok=1;
    rep(i,0,n) {
        rep(j,0,m) {
            if(s[i][j]=='1') {
                int l = j;
                int r = j;
                while(r+1<m && s[i][r+1]=='1') {
                    r++;
                }
                rep(i2,i,n) {
                    int ct = 0;
                    rep(j2,l,r+1) {
                        ct += s[i2][j2]=='1';
                    }
                    if(ct==r-l+1) {
                        if(l>0) {
                            ok &= s[i2][l-1]=='0';
                        }
                        if(r+1<m) {
                            ok &= s[i2][r+1]=='0';
                        }
                        rep(j2,l,r+1) {
                            s[i2][j2] = '0';
                        }
                    } else if(ct==0) {
                        break;
                    } else {
                        ok = 0;
                    }
                }
            }
            if(!ok) break;
        }
        if(!ok) break;
    }
    if(ok) {
        cout <<"YES\n";
    } else {
        cout <<"NO\n";
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