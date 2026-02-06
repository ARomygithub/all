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

const int mxn=3e5;
int n,t;
int a[mxn];
ll m;

const int mxa=5e3;
ll c[mxa+1][mxa+1];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    int sm = 0;
    rep(i,0,n) {
        sm += a[i];
    }
    ll ans = 1;
    rep(i,0,n) {
        ans = ans*c[sm][a[i]]%m;
        sm -= a[i];
    }
    cout <<ans <<"\n";
}

void init_fac() {
    rep(i,0,mxa+1) {
        rep(j,0,i+1) {
            if(j==0 || j==i) {
                c[i][j] = 1%m;
            } else {
                c[i][j] = (c[i-1][j-1] + c[i-1][j])%m;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t >>m;
    init_fac();
    while(t--) {
        solve();
    }
}