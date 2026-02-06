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
int n,k,t;
ll a[mxn],b[mxn],c[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i] >>b[i] >>c[i];
    }
    ll tm = 0;
    multiset<pll> s;
    ll cur = 0;
    rep(i,0,n) {
        while(cur + c[i] > k) {
            auto [ti, luar] = *s.begin();
            max_self(tm, ti);
            cur -= luar;
            s.erase(s.begin());
        }
        max_self(tm, a[i]);
        cout <<tm <<"\n";
        s.insert({tm+b[i],c[i]});
        cur += c[i];
    }
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