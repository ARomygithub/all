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

const int mxn=10;
int n;
int q[mxn],a[mxn],b[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>q[i];
    }
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    int ans = 0;
    for(int i=0;;i++) {
        int cta = 1e8;
        rep(j,0,n) {
            if(a[j]>0) {
                min_self(cta, q[j]/a[j]);
            }
        }
        max_self(ans,2*i+cta);
        int ctb = 1e8;
        rep(j,0,n) {
            if(b[j]>0) {
                min_self(ctb, q[j]/b[j]);
            }
        }
        max_self(ans,2*i+ctb);
        bool flag=1;
        rep(j,0,n) {
            q[j] -=(a[j]+b[j]);
            if(q[j]<0) flag = 0;
        }
        if(!flag) break;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}