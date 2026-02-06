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
int n,x,t;
ll a[mxn+1];

void solve() {
    cin >>n >>x;
    rep(i,1,n+1) {
        cin >>a[i];
    }
    vector<ll> p(n+1,0);
    rep(i,1,n+1) {
        p[i] = p[i-1]+a[i];
    }
    vector<int> r(n+1,n+1);
    rep(i,1,n+1) {
        ll temp = p[i-1]+x;
        auto it = upper_bound(p.begin(),p.end(),temp);
        r[i] = it-p.begin();
    }
    vector<int> ansi(n+1,0);
    ll ans = 0;
    per(i,n,0) {
        ll temp = r[i]-i;
        if(r[i]+1<=n) {
            temp += ansi[r[i]+1];
        }
        ansi[i] = temp;
        ans += temp;
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