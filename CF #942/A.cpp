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
int n,t;
ll k, a[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    sort(a,a+n);
    ll l = a[0], r = a[0]+k;
    ll mn = -1;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll ct = 0;
        rep(i,0,n) {
            if(a[i]<mid) {
                ct += mid-a[i];
            } else {
                break;
            }
        }
        if(ct<=k) {
            mn = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    int ct = 0;
    rep(i,0,n) {
        if(a[i]<mn) {
            k -= (mn-a[i]);
            a[i] = mn;
        }
        ct += (a[i]==mn);
    }
    ct -= k;
    ll ans = mn*n + (n-ct) - (n-1);
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
