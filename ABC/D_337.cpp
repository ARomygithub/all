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

const int mxn=1e5;
int n,m,k;

void solve() {
    cin >>n >>m >>k;
    vector<string> s(n);
    vector<vector<ll>> v(n, vector<ll>(m,1));
    rep(i,0,n) {
        cin >>s[i];
        rep(j,0,m) {
            if(s[i][j]=='x') {
                v[i][j] = 1e9;
            } else if(s[i][j]=='o') {
                v[i][j] = 0;
            }
        }
    }
    ll ans = 1e9;
    if(k<=m) {
        rep(i,0,n) {
            ll temp = 0;
            rep(j,0,k) {
                temp +=v[i][j];
            }
            rep(j,0,m-k+1) {
                if(j>0) {
                    temp -=v[i][j-1];
                    temp +=v[i][j+k-1];
                }
                min_self(ans, temp);
            }
        }
    }
    if(k<=n) {
        rep(i,0,m) {
            ll temp = 0;
            rep(j,0,k) {
                temp +=v[j][i];
            }
            rep(j,0,n-k+1) {
                if(j>0) {
                    temp -=v[j-1][i];
                    temp +=v[j+k-1][i];
                }
                min_self(ans, temp);
            }
        }
    }
    if(ans <= k) {
        cout <<ans <<"\n";
    } else {
        cout <<"-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}