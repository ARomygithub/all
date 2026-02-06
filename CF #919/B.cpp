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
int n,k,x,t;
int a[mxn+1];

void solve() {
    cin >>n >>k >>x;
    rep(i,1,n+1) {
        cin >>a[i];
    }
    sort(a,a+n+1);
    rep(i,1,n+1) {
        a[i] +=a[i-1];
    }
    int ans=-1e9;
    per(i,n,max(0,n-k)-1) {
        if(i>x) {
            int temp = a[i]-a[i-x];
            temp *=-1;
            temp +=a[i-x];
            max_self(ans, temp);
        } else {
            max_self(ans, a[i]*-1);
        }
    }
    cout <<ans <<"\n";
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