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

const int mxn=1e5;
int n,m,t;

void solve() {
    cin >>n >>m;
    vector v(n,vi());
    rep(i,0,n) {
        int szi; cin >>szi;
        v[i].resize(szi);
        rep(j,0,szi) {
            cin >>v[i][j];
        }
    }
    vi ct(m+1,0);
    rep(i,0,n) {
        rep(j,0,sz(v[i])) {
            ct[v[i][j]]++;
        }
    }
    rep(i,1,m+1) {
        if(ct[i]==0) {
            cout <<"NO\n";
            return;
        }
    }
    int ctv = 0;
    rep(i,0,n) {
        bool ok = 1;
        rep(j,0,sz(v[i])) {
            if(ct[v[i][j]]<2) {
                ok = 0;
                break;
            }
        }
        ctv += ok;
    }
    if(ctv>=2) {
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