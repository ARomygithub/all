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

const int mxn=3e5;
int n;
ll p[mxn],e[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>p[i] >>e[i];
    }
    ll ans = 0;
    rep(i,0,n) {
        ll l = p[i], r = p[i]*e[i];
        ll temp = -1;
        while(l<=r) {
            ll mid = (l+r)/2;
            ll u = mid;
            ll cur = 0;
            while(u) {
                cur += u/p[i];
                u /= p[i];
            }
            if(cur>=e[i]) {
                temp = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        max_self(ans, temp);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}