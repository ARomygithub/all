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

const int mxn=1e2;
int n,x,y,t;
int c[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>c[i];
    }
    cin >>x >>y;
    int ans = 0;
    int l = 0, r = 0;
    rep(i,0,n) {
        r += c[i];
    }
    rep(i,0,n) {
        if((l>=x && l<=y) && (r>=x && r<=y)) {
            cout <<i+1 <<"\n";
            return;
        }
        l += c[i];
        r -= c[i];
    }
    cout <<"0\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}