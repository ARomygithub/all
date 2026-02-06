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

const int mxn=1e5;
int n,t;
ll x;
ll a[mxn],b[mxn],c[mxn];
const ll inf = 2e18;

void solve() {
    cin >>n >>x;
    rep(i,0,n) {
        cin >>a[i] >>b[i] >>c[i];
    }
    ll ans = -1;
    ll cur = x;
    rep(i,0,n) {
        if(b[i]==1) continue;
        if(a[i] >= ((cur+b[i]-2)/(b[i]-1))) {
            cout <<"0\n";
            return;
        }
        cur -= a[i]*(b[i]-1);
    }
    ll mx = -inf;
    rep(i,0,n) {
        max_self(mx, a[i]*b[i]-c[i]);
    }
    if(mx>0) {
        ans = (cur+mx-1)/mx;
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