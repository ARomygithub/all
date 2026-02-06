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

const int mxn=1e3;
int n,m,t;
int a[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    if(m<n || n==2) {
        cout <<"-1\n";
        return;
    }
    int ans=0;
    rep(i,0,n) {
        ans +=a[i]*2;
    }
    cout <<ans <<"\n";
    rep(i,1,n+1) {
        cout <<i <<" " <<(i+1>n?1:i+1) <<"\n";
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