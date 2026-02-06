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

const int mxn=5e3;
const ll mod = 998244353;
int n;
int a[mxn];
ll ct[mxn+1],cta[mxn+1];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    sort(a,a+n);
    ct[0] = 1;
    ll ans = 0;
    rep(i,0,n) {
        rep(si, 0,a[i]) {
            ans = (ans + ct[si]*a[i]%mod)%mod;
            cta[si+a[i]] = (cta[si+a[i]] + ct[si])%mod;
        }
        per(s,mxn,a[i]-1) {
            ct[s] = (ct[s] + ct[s-a[i]])%mod;
        }
    }
    rep(i,0,mxn+1) {
        ans = (ans + (ct[i]-cta[i]+mod)%mod*((i+1)/2)%mod) %mod;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}