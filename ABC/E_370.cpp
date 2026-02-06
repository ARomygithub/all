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
const ll mod = 998244353;
int n;
ll k,a[mxn+1];

void solve() {
    cin >>n >>k;
    rep(i,1,n+1) {
        cin >>a[i];
    }
    rep(i,1,n+1) {
        a[i] += a[i-1];
    }
    vector<ll> ans(n+1,0);
    ll sm = 1;
    ans[0] = 1;
    map<ll,ll> mp;
    mp[k] = 1;
    rep(i,1,n+1) {
        ll cur = (sm - mp[a[i]] + mod)%mod;
        ans[i] = cur;
        sm = (sm+cur)%mod;
        mp[a[i]+k] = (mp[a[i]+k] + cur)%mod;
    }
    cout <<ans[n] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}