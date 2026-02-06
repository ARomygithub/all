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

const int mxn=1e6;
const ll mod=998244353;
int n,t;

void solve() {
    cin >>n;
    ll ans = 0;
    if(n==2) {
        ans +=1;
    } else {
        ans += 2;
    }
    if(n>3) {
        ll tmp = 1ll*(n-1)*(n)/2 - 3;
        ans = (ans + tmp)%mod;
    }
    vector<ll> to(n,0);
    to[n-1] = n;
    ll suf = n;
    per(i,n-2,3) {
        to[i] = suf*i%mod;
        to[i] = (to[i] + (i+1))%mod;
        suf = (suf + to[i])%mod;
    }
    rep(x,4,n) {
        ll tmp = 1ll*(x-2)*(x-1)/2 - 1;
        tmp %= mod;
        tmp = tmp*to[x]%mod;
        ans = (ans + tmp)%mod;
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