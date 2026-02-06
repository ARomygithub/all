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

const int mxn=1e5;
int n,a,b,t;
int c[mxn];

void solve() {
    cin >>n >>a >>b;
    rep(i,0,n) {
        cin >>c[i];
    }
    set<int> s;
    int d = __gcd(a,b);
    rep(i,0,n) {
        s.insert(c[i]%d);
    }
    vector<int> v(s.begin(),s.end());
    int ans = d;
    if(sz(v)==1) ans = 0;
    rep(i,0,sz(v)) {
        min_self(ans, d- ((i+1<sz(v)?v[i+1]:v[0]+d)-v[i]));
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