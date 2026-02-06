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

const int mxn=2e5;
int n,d,c;
ll a[mxn];

void solve() {
    cin >>n >>d >>c;
    rep(i,0,n) {
        cin >>a[i];
    }
    int x = 0;
    int l = 0, r = d;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll mn = c;
        ll pr = c;
        rep(i,0,n) {
            pr -= mid-a[i];
            min_self(mn, pr);
            min_self(pr, 1ll*c);
        }
        if(mn>=0) {
            x = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    int y = d;
    l = 0, r= d;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll mx = 0;
        ll pr = 0;
        rep(i,0,n) {
            pr -= mid - a[i];
            max_self(mx, pr);
            // min_self(pr, 1ll*c);
            max_self(pr, 0ll);
        }
        if(mx<=c) {
            y = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    // cout <<y <<" " <<x <<"\n";
    int ans = y-x;
    max_self(ans, 0);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}