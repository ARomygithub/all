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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=100,mxk=1e4;
int n,k;
pii ab[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>ab[i].se;
    }
    rep(i,0,n) {
        cin >>ab[i].fi;
    }
    rep(p,1,mxk+1) {
        int sm = 0;
        rep(i,0,n) {
            sm += min(ab[i].fi, ab[i].se*p);
        }
        if(k*p>=sm) {
            cout <<p <<"\n";
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