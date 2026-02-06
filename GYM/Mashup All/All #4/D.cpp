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

const int mxn=5e5;
int n,k;
int c[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>c[i];
    }
    sort(c,c+n);
    ll ans = -1e18;
    vector<ll> pr(n);
    rep(i,0,n) {
        pr[i] = (i>0?pr[i-1]:0) + c[i];
    }
    vector<ll> s(n,0);
    rep(i,0,n) {
        s[i] = (i>0?s[i-1]:0) + 1ll*i*c[i];
    }
    max_self(ans, s[n-1]);
    ll si = 0;
    rep(i,0,n) {
        si += 1ll*(i/(k+1))*c[i];
        ll temp = s[n-1]-s[i];
        ll cur = (i+1+k)/(k+1) - 1;
        temp += (cur-i)*(pr[n-1]-pr[i]);
        max_self(ans, si + temp);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}