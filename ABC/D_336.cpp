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

const int mxn=2e5;
int n;
int a[mxn],f[mxn],b[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    int ans=1;
    f[0] = 1;
    rep(i,1,n) {
        if(a[i]>=f[i-1]+1) {
            f[i] = f[i-1]+1;
        } else {
            f[i] = a[i];
        }
    }
    b[n-1] = 1;
    per(i,n-2,-1) {
        b[i] = min(a[i],b[i+1]+1);
    }
    rep(i,0,n) {
        max_self(ans, min(f[i],b[i]));
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}