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
ll n,b,x,t;
int c[mxn];

void solve() {
    cin >>n >>b >>x;
    int mx =0;
    rep(i,0,n) {
        cin >>c[i];
        max_self(mx, c[i]);
    }
    sort(c,c+n);
    vector<ll> add(mx, 0);
    ll last = 0;
    rep(i,0,n) {
        rep(j,0,c[i]) {
            ll avg = c[i]/(j+1);
            ll sisa = (c[i])%(j+1);
            ll temp = avg*(c[i]-avg)*(j+1-sisa);
            temp += (avg+1)*(c[i]-avg-1)*(sisa);
            temp /=2;
            temp *=b;
            add[j] += temp;
            if(i>0 && j>=c[i-1]) {
                add[j] += last;
            }
            if(j==c[i]-1) {
                last += temp;
            }
            // cout <<temp <<"\n";
        }
    }
    ll ans = -1e18;
    rep(i,0,mx) {
        max_self(ans, add[i]-x*i);
        // cout <<add[i] <<"\n";
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