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

const int mxn=1e5;
int n,q,t;
ll a[mxn];
ll x[mxn];

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,q) {
        cin >>x[i];
    }
    vector<int> ct(31);
    vector<int> add(31,0);
    iota(ct.begin(),ct.end(),0);
    rep(i,0,q) {
        rep(j,0,31) {
            if(ct[j]>=x[i]) {
                ct[j] = x[i]-1;
                add[j] +=(1ll<<(x[i]-1));
            }
        }
    }
    rep(i,0,n) {
        int b2 = __builtin_ctzll(a[i]);
        a[i] +=add[b2];
    }
    rep(i,0,n) {
        cout <<a[i] <<" \n"[i==n-1];
    }
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