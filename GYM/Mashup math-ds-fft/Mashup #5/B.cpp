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
const ll mod = 1e9+7;
int n,m;

void solve() {
    cin >>n >>m;
    vector<ll> v(max(max(n,m)+1,3),0);
    v[1] = 2, v[2] = 4; 
    rep(i,3,sz(v)) {
        v[i] = (v[i-1]+v[i-2])%mod;
    }
    ll ans = (v[n]+v[m])%mod;
    ans = (ans - 2 +mod)%mod;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}