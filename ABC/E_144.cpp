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

const int mxn=2e5;
int n;
ll k;
ll a[mxn],f[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>f[i];
    }
    ll l=0,r=1e12;
    ll ans = -1;
    sort(a,a+n);
    while(l<=r) {
        ll mid = (l+r)/2;
        vector<ll> c(n);
        rep(i,0,n) {
            c[i] = mid/f[i];
        }
        sort(c.begin(),c.end());
        ll temp = 0;
        per(i,n-1,-1) {
            if(a[i]-c[i]>0) {
                temp += a[i]-c[i];
            }
        }
        if(temp<=k) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}