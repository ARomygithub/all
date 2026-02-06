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

const int mxn=2e5;
const ll mod = 998244353;
int n;
ll a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    ll ans = 0;
    vector<ll> ct(11,0);
    vector<ll> pow(11);
    pow[0] = 1;
    rep(i,1,11) {
        pow[i] = pow[i-1]*10%mod;
    }
    per(i,n-1,-1) {
        ans = (ans + a[i]*i%mod)%mod;
        rep(j,1,11) {
            ans = (ans + a[i]*pow[j]%mod*ct[j]%mod) %mod;
        }
        int dig = 0;
        while(a[i]) {
            dig++;
            a[i] /=10;
        }
        ct[dig]++;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}