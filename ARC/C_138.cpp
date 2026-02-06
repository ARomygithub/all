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
int n;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<pii> v(n);
    vector<int> sign(n);
    rep(i,0,n) {
        v[i] = {a[i],i};
    }
    sort(v.begin(),v.end());
    ll s =0;
    rep(i,0,n/2) {
        sign[v[i].se] = 1;
    }
    rep(i,n/2,n) {
        sign[v[i].se] = -1;
        s += v[i].fi;
    }
    int posMn = 0;
    int mn = 0;
    int cur = 0;
    rep(i,0,n) {
        cur += sign[i];
        if(cur<=mn) {
            mn = cur;
            posMn = i+1;
        }
    }
    int k = posMn;
    if(k==n) {
        k = 0;
    }
    cout <<k <<" " <<s <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}