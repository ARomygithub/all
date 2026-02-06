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

const int mxn=50;
int n,t;

void solve() {
    cin >>n;
    vector<ll> v(n);
    rep(i,0,n) {
        cin >>v[i];
    }
    // if(n==1) {
    //     cout <<v[0] <<"\n";
    //     return;
    // }
    ll ans = -1e9;
    rep(i,0,n) {
        ll s = 0;
        rep(j,0,sz(v)) {
            s += v[j];
        }
        if(i>0) {
            s = abs(s);
        }
        max_self(ans, s);
        vector<ll> vn;
        rep(j,0,sz(v)-1) {
            vn.push_back(v[j]-v[j+1]);
        }
        v.swap(vn);
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