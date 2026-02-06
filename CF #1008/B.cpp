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
int t;

int ask(int x) {
    cout <<x <<"\n" <<flush;
    int ret; cin >>ret;
    return ret;
}

void solve() {
    int r0 = ask(0);
    int u = 0;
    for(int i=0;i<30;i+=2) {
        u += (1<<i);
    }
    int r1 = ask(u);
    r1 -= r0;
    vi v(30,-1);
    for(int i=0;i<30;i+=2) {
        if((r1>>i)&1) {
            v[i] = 1;
            r0 -= (1<<i);
        } else if((r1>>(i+1))&1) {
            v[i] = 0;
        } else {
            v[i] = 2;
            r0 -= (1<<i)*2;
        }
    }
    for(int i=1;i<30;i+=2) {
        if((r0>>i)&1) {
            v[i] =1;
        } else if((r0>>(i+1))&1) {
            v[i] = 2;
        } else {
            v[i] = 0;
        }
    }
    cout <<"!\n" <<flush;
    int m; cin >>m;
    int ret = 0;
    rep(i,0,30) {
        if((m>>i)&1) {
            ret += (1<<i)*2;
        } else {
            ret += (1<<i)*v[i];
        }
    }
    cout <<ret <<"\n" <<flush;
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