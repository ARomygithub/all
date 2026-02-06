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
int n;
ll x[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>x[i];
    }
    vector v(2, vector<ll>());
    rep(i,1,n) {
        v[i%2].push_back(x[i]-x[i-1]);
    }
    rep(i,0,2) {
        sort(all(v[i]));
    }
    ll ans = x[0]*n;
    rep(i,0,sz(v[1])) {
        ll mul = n-(i*2+1);
        ans += mul*v[1][i];
    }
    rep(i,0,sz(v[0])) {
        ll mul = n - (i+1)*2;
        ans += mul*v[0][i];
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}