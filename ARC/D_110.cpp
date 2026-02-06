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

const int mxn=2e3;
const ll mod=1e9+7;
int n,m;
int a[mxn];
const int mxa=4e6+2e3;
ll iv[mxa+1];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    int sa = 0;
    rep(i,0,n) {
        sa += a[i];
    }
    if(sa>m) {
        cout <<"0\n";
        return;
    }
    ll ans = 1;
    for(ll ats=m+n,bwh=sa+n; bwh>0;ats--,bwh--) {
        ans = ans*ats%mod;
        ans = ans*iv[bwh]%mod;
    }
    cout <<ans <<"\n";
}

void init_fac() {
    iv[1] = 1;
    rep(i,2,mxa+1) {
        iv[i] = mod - mod/i*iv[mod%i]%mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_fac();
    solve();
}