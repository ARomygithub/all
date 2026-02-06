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

const int mxn=1e5;
int n;
int a[mxn*3];

void solve() {
    cin >>n;
    rep(i,0,n*3) {
        cin >>a[i];
    }
    vector<ll> mx(n*3,0), mn(n*3,1e18);
    multiset<int> ms;
    ll s = 0;
    rep(i,0,n*2) {
        if(i<n) {
            s += a[i];
            ms.insert(a[i]);
            mx[i] = s;
        } else {
            s += a[i];
            ms.insert(a[i]);
            s -= *ms.begin();
            ms.erase(ms.begin());
            mx[i] = s;
        }
    }
    ms.clear();
    s = 0;
    per(i,n*3-1,n-1) {
        if(n*3-i <=n) {
            s += a[i];
            ms.insert(a[i]);
            mn[i] = s;
        } else {
            s += a[i];
            ms.insert(a[i]);
            s -= *(--ms.end());
            ms.erase(--ms.end());
            mn[i] = s;
        }
    }
    ll ans = -1e18;
    rep(i,n-1,n*2) {
        max_self(ans, mx[i]-mn[i+1]);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}