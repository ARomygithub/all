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

const int mxn=50;
int n,m;
string s[mxn],t[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    rep(i,0,m) {
        cin >>t[i];
    }
    rep(i,0,n-m+1) {
        rep(j,0,n-m+1) {
            bool ok = 1;
            rep(i2,0,m) {
                rep(j2,0,m) {
                    ok = ok && (s[i+i2][j+j2]==t[i2][j2]);
                }
            }
            if(ok) {
                cout <<i+1 <<" " <<j+1 <<"\n";
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}