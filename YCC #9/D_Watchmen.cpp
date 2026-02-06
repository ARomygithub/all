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
int n,t;
int x[mxn],y[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>x[i] >>y[i];
    }
    map<int,int> mx, my;
    map<pii,int> mp;
    rep(i,0,n) {
        mp[{x[i],y[i]}]++;
        mx[x[i]]++;
        my[y[i]]++;
    }
    ll ans = 0;
    rep(i,0,n) {
        ll ad = (mx[x[i]]-1)+(my[y[i]]-1) - (mp[{x[i],y[i]}]-1);
        ans += ad;
    }
    ans /= 2;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}