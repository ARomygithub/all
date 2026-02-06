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

const int mxn=1e3;
int n,m;
string s[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    int l=m,r=-1,u=n,d=-1;
    rep(i,0,n) {
        rep(j,0,m) {
            if(s[i][j]=='#') {
                min_self(l, j);
                max_self(r, j);
                max_self(d, i);
                min_self(u, i);
            }
        }
    }
    bool ok = 1;
    rep(i,u,d+1) {
        rep(j,l,r+1) {
            if(s[i][j] == '.') {
                ok = 0;
                break;
            }
        }
    }
    if(ok) {
        cout <<"Yes\n";
    } else {
        cout <<"No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}