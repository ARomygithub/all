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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e6;
int n;
int a[mxn];
bool isPrime[mxn+1];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<ll> pref(n,0);
    rep(i,0,n) {
        pref[i] = 1ll*a[i] + (i>0?pref[i-1]:0ll);
    }
    ll ans = 2e18;
    ll u = pref[n-1];
    for(int i=2;1ll*i*i<=u;i++) {
        if(isPrime[i] && (pref[n-1]%i)==0) {
            ll temp = 0;
            rep(j,0,n) {
                temp += min(pref[j]%i, i - (pref[j]%i));
            }
            min_self(ans, temp);
            while((u%i)==0) {
                u /=i;
            }
        }
    }
    if(u>1) {
        ll temp = 0;
        rep(i,0,n) {
            temp += min(pref[i]%(u), u - (pref[i]%u));
        }
        min_self(ans, temp);
    }
    if(ans == 2e18) {
        cout <<"-1\n";
    } else {
        cout <<ans <<"\n";
    }
}

void init() {
    fill(isPrime,isPrime+mxn+1,true);
    rep(i,2,mxn+1) {
        if(isPrime[i]) {
            for(int j=i*2;j<=mxn;j+=i) {
                isPrime[j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}