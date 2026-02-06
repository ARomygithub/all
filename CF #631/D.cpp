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

const int mxn=1e9;
int t;
int n;
ll m;

void solve() {
    cin >>n >>m;
    int ctbit = 32 - __builtin_clz(n);
    vector<ll> h(ctbit);
    h[0] = (1)%m;
    rep(i,1,ctbit) {
        ll temp = min(n+1, 1<<(i+1)) - (1<<i);
        h[i] = h[i-1]*(temp + 1)%m;
        h[i] = (h[i] + temp)%m;
    }
    cout <<h[ctbit-1] <<"\n";
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